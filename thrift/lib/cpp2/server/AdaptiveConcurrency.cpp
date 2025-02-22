/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <thrift/lib/cpp2/server/AdaptiveConcurrency.h>

#include <algorithm>
#include <atomic>
#include <chrono>

#include <folly/Random.h>

using Clock = std::chrono::steady_clock;

namespace apache {
namespace thrift {

namespace {
constexpr auto kZero = Clock::time_point{};

Clock::duration jitter(Clock::duration d, double jitter) {
  jitter = std::min(1.0, std::max(0.0, jitter));

  if (jitter == 0.0) {
    return d;
  }

  return Clock::duration{folly::Random::rand64(
      std::chrono::round<Clock::duration>(d - d * jitter).count(),
      std::chrono::round<Clock::duration>(d + d * jitter).count())};
}
} // namespace

AdaptiveConcurrencyController::AdaptiveConcurrencyController(
    folly::observer::Observer<AdaptiveConcurrencyController::Config> oConfig,
    folly::observer::Observer<uint32_t> maxRequestsLimit)
    : config_(std::move(oConfig)),
      maxRequestsLimit_(std::move(maxRequestsLimit)),
      concurrencyLimit_(config().minConcurrency) {
  rttRecalcStart_ = config().isEnabled() ? Clock::now() : kZero;
  enablingCallback_ = config_.addCallback([this](auto snapshot) {
    rttRecalcStart_ = snapshot->isEnabled() ? Clock::now() : kZero;
    // reset all the state
    maxRequests_.store(0, std::memory_order_relaxed);
    nextRttRecalcStart_.store(kZero, std::memory_order_relaxed);
    samplingPeriodStart_.store(kZero, std::memory_order_relaxed);
    latencySamplesIdx_.store(0, std::memory_order_relaxed);
    latencySamplesCnt_.store(0, std::memory_order_relaxed);
    concurrencyLimit_ = snapshot->minConcurrency;
  });
}

bool AdaptiveConcurrencyController::inSamplingPeriod(
    Clock::time_point ts) const {
  auto start = samplingPeriodStart_.load(std::memory_order_relaxed);
  return start != kZero && ts > start;
}

void AdaptiveConcurrencyController::requestStarted(Clock::time_point started) {
  auto rttRecalc = rttRecalcStart_.load(std::memory_order_relaxed);
  if (rttRecalc == kZero || started < rttRecalc) {
    return;
  }
  rttRecalc = rttRecalcStart_.exchange(kZero, std::memory_order_relaxed);
  if (rttRecalc != kZero) {
    DCHECK(samplingPeriodStart_.load(std::memory_order_relaxed) == kZero);
    DCHECK(config().isEnabled());

    // tell the server to start enforcing min concurrency
    maxRequests_.store(config().minConcurrency, std::memory_order_relaxed);
    // reset targetRtt to 0 to indicate that we are computing targetRtt
    targetRtt_.store({}, std::memory_order_relaxed);
    // and start collecting samples for requests running with this concurrency
    samplingPeriodStart_.store(Clock::now(), std::memory_order_relaxed);
    if (config().targetRttFixed.count() == 0) {
      // and schedule next rtt recalc, with jitter
      auto dur = jitter(config().recalcInterval, config().recalcPeriodJitter);
      nextRttRecalcStart_.store(Clock::now() + dur, std::memory_order_relaxed);
    }
  }
}

void AdaptiveConcurrencyController::requestFinished(
    Clock::time_point started, Clock::time_point finished) {
  if (!inSamplingPeriod(started)) {
    return;
  }
  auto idx = latencySamplesIdx_.fetch_add(1, std::memory_order_relaxed);
  if (idx >= latencySamples_.size()) {
    return;
  }

  latencySamples_[idx] = finished - started;
  auto count = latencySamplesCnt_.fetch_add(1, std::memory_order_acq_rel);
  bool shouldRecalculate = count == latencySamples_.size() - 1;
  if (shouldRecalculate) {
    samplingPeriodStart_.store(kZero, std::memory_order_relaxed);
    recalculate();

    // start recalibration for requests that will start running in 500ms
    auto now = Clock::now();
    auto nextRttRecalc = nextRttRecalcStart_.load(std::memory_order_relaxed);
    if (nextRttRecalc != kZero &&
        now + config().samplingInterval > nextRttRecalc) {
      rttRecalcStart_.store(nextRttRecalc, std::memory_order_relaxed);
    } else {
      samplingPeriodStart_.store(
          now + config().samplingInterval, std::memory_order_relaxed);
    }
    latencySamplesIdx_.store(0, std::memory_order_relaxed);
    latencySamplesCnt_.store(0, std::memory_order_relaxed);
  }
}

void AdaptiveConcurrencyController::recalculate() {
  auto p95 = latencySamples_.begin() +
      static_cast<size_t>(latencySamples_.size() * 0.95);
  std::nth_element(latencySamples_.begin(), p95, latencySamples_.end());
  Duration p95rtt{*p95};
  sampledRtt_.store(p95rtt, std::memory_order_relaxed); // for monitoring
  const auto& cfg = config();
  if (targetRtt_.load(std::memory_order_relaxed) == Duration{}) {
    if (cfg.targetRttFixed == std::chrono::milliseconds{}) {
      targetRtt_.store(
          std::chrono::round<Clock::duration>(p95rtt * cfg.targetRttFactor),
          std::memory_order_relaxed);
    } else {
      targetRtt_.store(
          Clock::duration{cfg.targetRttFixed}, std::memory_order_relaxed);
    }
    // reset concurrency limit to what it was before we started rtt calibration
    maxRequests_.store(concurrencyLimit_, std::memory_order_relaxed);
  } else {
    double raw_gradient = targetRtt_.load(std::memory_order_relaxed) / p95rtt;
    double gradient = std::max(0.5, std::min(2.0, raw_gradient));

    double limit = concurrencyLimit_ * gradient;
    double headroom = std::sqrt(limit);
    auto newLimit = static_cast<size_t>(limit + headroom);

    uint32_t maxRequests = **maxRequestsLimit_;
    // limit concurrency at 1000 but respect server's maxRequests value
    size_t upperConcurrencyLimit =
        maxRequests == 0 ? 1000u : std::min(1000u, maxRequests);
    concurrencyLimit_ =
        std::max(cfg.minConcurrency, std::min(newLimit, upperConcurrencyLimit));
    maxRequests_.store(concurrencyLimit_, std::memory_order_relaxed);
  }
}

size_t AdaptiveConcurrencyController::getMaxRequests() const {
  return maxRequests_.load(std::memory_order_relaxed);
}

Clock::time_point AdaptiveConcurrencyController::samplingPeriodStart() const {
  return samplingPeriodStart_.load(std::memory_order_relaxed);
}
void AdaptiveConcurrencyController::samplingPeriodStart(Clock::time_point v) {
  samplingPeriodStart_.store(v, std::memory_order_relaxed);
}
Clock::time_point AdaptiveConcurrencyController::rttRecalcStart() const {
  return rttRecalcStart_.load(std::memory_order_relaxed);
}
Clock::time_point AdaptiveConcurrencyController::nextRttRecalcStart() const {
  return nextRttRecalcStart_.load(std::memory_order_relaxed);
}
void AdaptiveConcurrencyController::nextRttRecalcStart(Clock::time_point v) {
  nextRttRecalcStart_.store(v, std::memory_order_relaxed);
}

std::chrono::microseconds AdaptiveConcurrencyController::targetRtt() const {
  return std::chrono::round<std::chrono::microseconds>(
      targetRtt_.load(std::memory_order_relaxed));
}

std::chrono::microseconds AdaptiveConcurrencyController::sampledRtt() const {
  return std::chrono::round<std::chrono::microseconds>(
      sampledRtt_.load(std::memory_order_relaxed));
}

size_t AdaptiveConcurrencyController::getMinConcurrency() const {
  return config().minConcurrency;
}

size_t AdaptiveConcurrencyController::getConcurrency() const {
  return concurrencyLimit_.load(std::memory_order_relaxed);
}

} // namespace thrift
} // namespace apache
