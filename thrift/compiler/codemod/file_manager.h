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

#pragma once

#include <stddef.h>
#include <set>
#include <stdexcept>
#include <unordered_set>

#include <folly/FileUtil.h>

#include <thrift/compiler/ast/source_range.h>
#include <thrift/compiler/ast/t_program.h>

namespace apache {
namespace thrift {
namespace compiler {
namespace codemod {

struct replacement {
  // TODO(urielrivas): Revisit this whether we want to consider using a
  // source_range directly instead of offset begin_pos, end_pos.
  size_t begin_pos;
  size_t end_pos;
  std::string new_content;

  constexpr bool operator<(const replacement& replace) const noexcept {
    if (begin_pos != replace.begin_pos) {
      return begin_pos < replace.begin_pos;
    }
    return end_pos < replace.end_pos;
  }
};

/**
 * Class file_manager
 *
 * A manager to control all replacements needed to do for a Thrift file.
 */
class file_manager {
 public:
  explicit file_manager(const t_program& program) : program_(&program) {
    if (!folly::readFile(program_->path().c_str(), old_content_)) {
      throw std::runtime_error("Could not read file: " + program_->path());
    }
    for (const auto* include : program_->includes()) {
      includes_.insert(include->get_doc());
    }
  }

  // Write all existing replacements back to file.
  void apply_replacements();

  // Adds a given replacement to the set of replacements.
  void add(replacement replace) { replacements_.insert(std::move(replace)); }

  const std::string_view old_content() const noexcept { return old_content_; }

  // Adds a given include to the set of replacements.
  void add_include(std::string include);

  // Adds a replacement to remove the given element.
  void remove(const t_annotation& annotation);

  // Removes all annotations from a given t_node.
  void remove_all_annotations(const t_node& node);

 private:
  // Gets the line number of the first include in program's includes_.
  size_t get_last_include_offset() const;

  // Expands backwards begin_offset and forwards end_offset for all whitespaces.
  void expand_over_whitespaces(
      size_t& begin_offset, size_t& end_offset) const noexcept;

  const t_program* program_;
  std::string old_content_;
  std::set<replacement> replacements_;
  std::unordered_set<std::string> includes_;
};

} // namespace codemod
} // namespace compiler
} // namespace thrift
} // namespace apache
