/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/stream/gen-cpp2/PubSubStreamingService.h"
#include "thrift/compiler/test/fixtures/stream/gen-cpp2/PubSubStreamingService.tcc"
#include "thrift/compiler/test/fixtures/stream/gen-cpp2/module_metadata.h"
#include <thrift/lib/cpp2/gen/service_cpp.h>

namespace cpp2 {
std::unique_ptr<apache::thrift::AsyncProcessor> PubSubStreamingServiceSvIf::getProcessor() {
  return std::make_unique<PubSubStreamingServiceAsyncProcessor>(this);
}

PubSubStreamingServiceSvIf::CreateMethodMetadataResult PubSubStreamingServiceSvIf::createMethodMetadata() {
  return ::apache::thrift::detail::ap::createMethodMetadataMap<PubSubStreamingServiceAsyncProcessor>();
}


::apache::thrift::ServerStream<::std::int32_t> PubSubStreamingServiceSvIf::returnstream(::std::int32_t /*i32_from*/, ::std::int32_t /*i32_to*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("returnstream");
}

folly::SemiFuture<::apache::thrift::ServerStream<::std::int32_t>> PubSubStreamingServiceSvIf::semifuture_returnstream(::std::int32_t p_i32_from, ::std::int32_t p_i32_to) {
  auto expected{apache::thrift::detail::si::InvocationType::SemiFuture};
  __fbthrift_invocation_returnstream.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Sync, std::memory_order_relaxed);
  return returnstream(p_i32_from, p_i32_to);
}

folly::Future<::apache::thrift::ServerStream<::std::int32_t>> PubSubStreamingServiceSvIf::future_returnstream(::std::int32_t p_i32_from, ::std::int32_t p_i32_to) {
  auto expected{apache::thrift::detail::si::InvocationType::Future};
  __fbthrift_invocation_returnstream.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::SemiFuture, std::memory_order_relaxed);
  return apache::thrift::detail::si::future(semifuture_returnstream(p_i32_from, p_i32_to), getInternalKeepAlive());
}

void PubSubStreamingServiceSvIf::async_tm_returnstream(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::ServerStream<::std::int32_t>>> callback, ::std::int32_t p_i32_from, ::std::int32_t p_i32_to) {
  // It's possible the coroutine versions will delegate to a future-based
  // version. If that happens, we need the RequestParams arguments to be
  // available to the future through the thread-local backchannel, so we create
  // a RAII object that sets up RequestParams and clears them on destruction.
  apache::thrift::detail::si::AsyncTmPrep asyncTmPrep(this, callback.get());
  auto invocationType = __fbthrift_invocation_returnstream.load(std::memory_order_relaxed);
  try {
    switch (invocationType) {
      case apache::thrift::detail::si::InvocationType::AsyncTm:
      {
        __fbthrift_invocation_returnstream.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
        FOLLY_FALLTHROUGH;
      }
      case apache::thrift::detail::si::InvocationType::Future:
      {
        auto fut = future_returnstream(p_i32_from, p_i32_to);
        apache::thrift::detail::si::async_tm_future(std::move(callback), std::move(fut));
        return;
      }
      case apache::thrift::detail::si::InvocationType::SemiFuture:
      {
        auto fut = semifuture_returnstream(p_i32_from, p_i32_to);
        apache::thrift::detail::si::async_tm_semifuture(std::move(callback), std::move(fut));
        return;
      }
      case apache::thrift::detail::si::InvocationType::Sync:
      {
        callback->result(returnstream(p_i32_from, p_i32_to));
        return;
      }
      default:
      {
        folly::assume_unreachable();
      }
    }
  } catch (...) {
    callback->exception(std::current_exception());
  }
}

::apache::thrift::ServerStream<::std::int32_t> PubSubStreamingServiceSvIf::streamthrows(::std::int32_t /*foo*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("streamthrows");
}

folly::SemiFuture<::apache::thrift::ServerStream<::std::int32_t>> PubSubStreamingServiceSvIf::semifuture_streamthrows(::std::int32_t p_foo) {
  auto expected{apache::thrift::detail::si::InvocationType::SemiFuture};
  __fbthrift_invocation_streamthrows.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Sync, std::memory_order_relaxed);
  return streamthrows(p_foo);
}

folly::Future<::apache::thrift::ServerStream<::std::int32_t>> PubSubStreamingServiceSvIf::future_streamthrows(::std::int32_t p_foo) {
  auto expected{apache::thrift::detail::si::InvocationType::Future};
  __fbthrift_invocation_streamthrows.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::SemiFuture, std::memory_order_relaxed);
  return apache::thrift::detail::si::future(semifuture_streamthrows(p_foo), getInternalKeepAlive());
}

void PubSubStreamingServiceSvIf::async_tm_streamthrows(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::ServerStream<::std::int32_t>>> callback, ::std::int32_t p_foo) {
  // It's possible the coroutine versions will delegate to a future-based
  // version. If that happens, we need the RequestParams arguments to be
  // available to the future through the thread-local backchannel, so we create
  // a RAII object that sets up RequestParams and clears them on destruction.
  apache::thrift::detail::si::AsyncTmPrep asyncTmPrep(this, callback.get());
  auto invocationType = __fbthrift_invocation_streamthrows.load(std::memory_order_relaxed);
  try {
    switch (invocationType) {
      case apache::thrift::detail::si::InvocationType::AsyncTm:
      {
        __fbthrift_invocation_streamthrows.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
        FOLLY_FALLTHROUGH;
      }
      case apache::thrift::detail::si::InvocationType::Future:
      {
        auto fut = future_streamthrows(p_foo);
        apache::thrift::detail::si::async_tm_future(std::move(callback), std::move(fut));
        return;
      }
      case apache::thrift::detail::si::InvocationType::SemiFuture:
      {
        auto fut = semifuture_streamthrows(p_foo);
        apache::thrift::detail::si::async_tm_semifuture(std::move(callback), std::move(fut));
        return;
      }
      case apache::thrift::detail::si::InvocationType::Sync:
      {
        callback->result(streamthrows(p_foo));
        return;
      }
      default:
      {
        folly::assume_unreachable();
      }
    }
  } catch (...) {
    callback->exception(std::current_exception());
  }
}

::apache::thrift::ServerStream<::std::int32_t> PubSubStreamingServiceSvIf::boththrows(::std::int32_t /*foo*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("boththrows");
}

folly::SemiFuture<::apache::thrift::ServerStream<::std::int32_t>> PubSubStreamingServiceSvIf::semifuture_boththrows(::std::int32_t p_foo) {
  auto expected{apache::thrift::detail::si::InvocationType::SemiFuture};
  __fbthrift_invocation_boththrows.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Sync, std::memory_order_relaxed);
  return boththrows(p_foo);
}

folly::Future<::apache::thrift::ServerStream<::std::int32_t>> PubSubStreamingServiceSvIf::future_boththrows(::std::int32_t p_foo) {
  auto expected{apache::thrift::detail::si::InvocationType::Future};
  __fbthrift_invocation_boththrows.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::SemiFuture, std::memory_order_relaxed);
  return apache::thrift::detail::si::future(semifuture_boththrows(p_foo), getInternalKeepAlive());
}

void PubSubStreamingServiceSvIf::async_tm_boththrows(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::ServerStream<::std::int32_t>>> callback, ::std::int32_t p_foo) {
  // It's possible the coroutine versions will delegate to a future-based
  // version. If that happens, we need the RequestParams arguments to be
  // available to the future through the thread-local backchannel, so we create
  // a RAII object that sets up RequestParams and clears them on destruction.
  apache::thrift::detail::si::AsyncTmPrep asyncTmPrep(this, callback.get());
  auto invocationType = __fbthrift_invocation_boththrows.load(std::memory_order_relaxed);
  try {
    switch (invocationType) {
      case apache::thrift::detail::si::InvocationType::AsyncTm:
      {
        __fbthrift_invocation_boththrows.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
        FOLLY_FALLTHROUGH;
      }
      case apache::thrift::detail::si::InvocationType::Future:
      {
        auto fut = future_boththrows(p_foo);
        apache::thrift::detail::si::async_tm_future(std::move(callback), std::move(fut));
        return;
      }
      case apache::thrift::detail::si::InvocationType::SemiFuture:
      {
        auto fut = semifuture_boththrows(p_foo);
        apache::thrift::detail::si::async_tm_semifuture(std::move(callback), std::move(fut));
        return;
      }
      case apache::thrift::detail::si::InvocationType::Sync:
      {
        callback->result(boththrows(p_foo));
        return;
      }
      default:
      {
        folly::assume_unreachable();
      }
    }
  } catch (...) {
    callback->exception(std::current_exception());
  }
}

::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t> PubSubStreamingServiceSvIf::responseandstreamthrows(::std::int32_t /*foo*/) {
  apache::thrift::detail::si::throw_app_exn_unimplemented("responseandstreamthrows");
}

folly::SemiFuture<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>> PubSubStreamingServiceSvIf::semifuture_responseandstreamthrows(::std::int32_t p_foo) {
  auto expected{apache::thrift::detail::si::InvocationType::SemiFuture};
  __fbthrift_invocation_responseandstreamthrows.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::Sync, std::memory_order_relaxed);
  return responseandstreamthrows(p_foo);
}

folly::Future<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>> PubSubStreamingServiceSvIf::future_responseandstreamthrows(::std::int32_t p_foo) {
  auto expected{apache::thrift::detail::si::InvocationType::Future};
  __fbthrift_invocation_responseandstreamthrows.compare_exchange_strong(expected, apache::thrift::detail::si::InvocationType::SemiFuture, std::memory_order_relaxed);
  return apache::thrift::detail::si::future(semifuture_responseandstreamthrows(p_foo), getInternalKeepAlive());
}

void PubSubStreamingServiceSvIf::async_tm_responseandstreamthrows(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::ResponseAndServerStream<::std::int32_t, ::std::int32_t>>> callback, ::std::int32_t p_foo) {
  // It's possible the coroutine versions will delegate to a future-based
  // version. If that happens, we need the RequestParams arguments to be
  // available to the future through the thread-local backchannel, so we create
  // a RAII object that sets up RequestParams and clears them on destruction.
  apache::thrift::detail::si::AsyncTmPrep asyncTmPrep(this, callback.get());
  auto invocationType = __fbthrift_invocation_responseandstreamthrows.load(std::memory_order_relaxed);
  try {
    switch (invocationType) {
      case apache::thrift::detail::si::InvocationType::AsyncTm:
      {
        __fbthrift_invocation_responseandstreamthrows.compare_exchange_strong(invocationType, apache::thrift::detail::si::InvocationType::Future, std::memory_order_relaxed);
        FOLLY_FALLTHROUGH;
      }
      case apache::thrift::detail::si::InvocationType::Future:
      {
        auto fut = future_responseandstreamthrows(p_foo);
        apache::thrift::detail::si::async_tm_future(std::move(callback), std::move(fut));
        return;
      }
      case apache::thrift::detail::si::InvocationType::SemiFuture:
      {
        auto fut = semifuture_responseandstreamthrows(p_foo);
        apache::thrift::detail::si::async_tm_semifuture(std::move(callback), std::move(fut));
        return;
      }
      case apache::thrift::detail::si::InvocationType::Sync:
      {
        callback->result(responseandstreamthrows(p_foo));
        return;
      }
      default:
      {
        folly::assume_unreachable();
      }
    }
  } catch (...) {
    callback->exception(std::current_exception());
  }
}

void PubSubStreamingServiceSvIf::async_eb_returnstreamFast(std::unique_ptr<apache::thrift::HandlerCallback<::apache::thrift::ServerStream<::std::int32_t>>> callback, ::std::int32_t /*i32_from*/, ::std::int32_t /*i32_to*/) {
  callback->exception(apache::thrift::TApplicationException("Function returnstreamFast is unimplemented"));
}



const char* PubSubStreamingServiceAsyncProcessor::getServiceName() {
  return "PubSubStreamingService";
}

void PubSubStreamingServiceAsyncProcessor::getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) {
  ::apache::thrift::detail::md::ServiceMetadata<PubSubStreamingServiceSvIf>::gen(response);
}

void PubSubStreamingServiceAsyncProcessor::processSerializedCompressedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  apache::thrift::detail::ap::process(this, std::move(req), std::move(serializedRequest), protType, context, eb, tm);
}

void PubSubStreamingServiceAsyncProcessor::processSerializedCompressedRequestWithMetadata(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  apache::thrift::detail::ap::process(this, std::move(req), std::move(serializedRequest), methodMetadata, protType, context, eb, tm);
}

const PubSubStreamingServiceAsyncProcessor::ProcessMap& PubSubStreamingServiceAsyncProcessor::getOwnProcessMap() {
  return kOwnProcessMap_;
}

const PubSubStreamingServiceAsyncProcessor::ProcessMap PubSubStreamingServiceAsyncProcessor::kOwnProcessMap_ {
  {"returnstream", {&PubSubStreamingServiceAsyncProcessor::setUpAndProcess_returnstream<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>, &PubSubStreamingServiceAsyncProcessor::setUpAndProcess_returnstream<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>}},
  {"streamthrows", {&PubSubStreamingServiceAsyncProcessor::setUpAndProcess_streamthrows<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>, &PubSubStreamingServiceAsyncProcessor::setUpAndProcess_streamthrows<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>}},
  {"boththrows", {&PubSubStreamingServiceAsyncProcessor::setUpAndProcess_boththrows<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>, &PubSubStreamingServiceAsyncProcessor::setUpAndProcess_boththrows<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>}},
  {"responseandstreamthrows", {&PubSubStreamingServiceAsyncProcessor::setUpAndProcess_responseandstreamthrows<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>, &PubSubStreamingServiceAsyncProcessor::setUpAndProcess_responseandstreamthrows<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>}},
  {"returnstreamFast", {&PubSubStreamingServiceAsyncProcessor::setUpAndProcess_returnstreamFast<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>, &PubSubStreamingServiceAsyncProcessor::setUpAndProcess_returnstreamFast<apache::thrift::BinaryProtocolReader, apache::thrift::BinaryProtocolWriter>}},
};

} // cpp2
