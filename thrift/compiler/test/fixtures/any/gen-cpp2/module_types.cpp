/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include "thrift/compiler/test/fixtures/any/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/any/gen-cpp2/module_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>
#include <thrift/conformance/cpp2/AnyRegistry.h>

#include "thrift/compiler/test/fixtures/any/gen-cpp2/module_data.h"

namespace cpp2 {
// Static-init time registration for dynamically-linked libraries.
//
// To include in statically-linked libraties, link whole (e.g. --whole-archive)
// `module_sinit.cpp`.
FOLLY_EXPORT bool __fbthrift_static_init_module = (
    apache::thrift::conformance::detail::registerGeneratedStruct<
        MyStruct,
        apache::thrift::conformance::StandardProtocol::Compact,
        apache::thrift::conformance::StandardProtocol::Binary>(),
    apache::thrift::conformance::detail::registerGeneratedStruct<
        MyUnion,
        apache::thrift::conformance::StandardProtocol::Compact,
        apache::thrift::conformance::StandardProtocol::Binary>(),
    apache::thrift::conformance::detail::registerGeneratedStruct<
        MyException,
        apache::thrift::conformance::StandardProtocol::Compact,
        apache::thrift::conformance::StandardProtocol::Binary>(),
    true);
} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::MyStruct>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::MyStruct>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

const char* MyStruct::__fbthrift_cpp2_gen_thrift_uri() {
  return "facebook.com/thrift/compiler/test/fixtures/any/MyStruct";
}

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
MyStruct::MyStruct(const MyStruct&) = default;
MyStruct& MyStruct::operator=(const MyStruct&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
MyStruct::MyStruct(MyStruct&& other) noexcept  :
    myString(std::move(other.myString)),
    __isset(other.__isset) {}
MyStruct& MyStruct::operator=(FOLLY_MAYBE_UNUSED MyStruct&& other) noexcept {
    this->myString = std::move(other.myString);
    __isset = other.__isset;
    return *this;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END


THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
MyStruct::MyStruct(apache::thrift::FragileConstructor, ::std::string myString__arg) :
    myString(std::move(myString__arg)) {
  __isset.__fbthrift_set(folly::index_constant<0>(), true);
}
THRIFT_IGNORE_ISSET_USE_WARNING_END

void MyStruct::__clear() {
  // clear all fields
  this->myString = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset = {};
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

bool MyStruct::operator==(const MyStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.myString_ref() == rhs.myString_ref())) {
    return false;
  }
  return true;
}

bool MyStruct::operator<(const MyStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.myString_ref() == rhs.myString_ref())) {
    return lhs.myString_ref() < rhs.myString_ref();
  }
  return false;
}


void swap(MyStruct& a, MyStruct& b) {
  using ::std::swap;
  swap(a.myString_ref().value(), b.myString_ref().value());
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  swap(a.__isset, b.__isset);
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

template void MyStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MyStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MyStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MyStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::MyUnion>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::MyUnion>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace apache { namespace thrift {

constexpr std::size_t const TEnumTraits<::cpp2::MyUnion::Type>::size;
folly::Range<::cpp2::MyUnion::Type const*> const TEnumTraits<::cpp2::MyUnion::Type>::values = folly::range(TEnumDataStorage<::cpp2::MyUnion::Type>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::cpp2::MyUnion::Type>::names = folly::range(TEnumDataStorage<::cpp2::MyUnion::Type>::names);

char const* TEnumTraits<::cpp2::MyUnion::Type>::findName(type value) {
  using factory = detail::TEnumMapFactory<::cpp2::MyUnion::Type>;
  static folly::Indestructible<factory::ValuesToNamesMapType> const map{
      factory::makeValuesToNamesMap()};
  auto found = map->find(value);
  return found == map->end() ? nullptr : found->second;
}

bool TEnumTraits<::cpp2::MyUnion::Type>::findValue(char const* name, type* out) {
  using factory = detail::TEnumMapFactory<::cpp2::MyUnion::Type>;
  static folly::Indestructible<factory::NamesToValuesMapType> const map{
      factory::makeNamesToValuesMap()};
  auto found = map->find(name);
  return found == map->end() ? false : (*out = found->second, true);
}
}} // apache::thrift
namespace cpp2 {

const char* MyUnion::__fbthrift_cpp2_gen_thrift_uri() {
  return "facebook.com/thrift/compiler/test/fixtures/any/MyUnion";
}

void MyUnion::__clear() {
  // clear all fields
  if (type_ == Type::__EMPTY__) { return; }
  switch(type_) {
    case Type::myString:
      destruct(value_.myString);
      break;
    default:
      assert(false);
      break;
  }
  type_ = Type::__EMPTY__;
}

bool MyUnion::operator==(const MyUnion& rhs) const {
  if (type_ != rhs.type_) { return false; }
  switch(type_) {
    case Type::myString:
      return value_.myString == rhs.value_.myString;
    default:
      return true;
  }
}

bool MyUnion::operator<(const MyUnion& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (lhs.type_ != rhs.type_) {
    return lhs.type_ < rhs.type_;
  }
  switch (lhs.type_) {
    case Type::myString:
      return lhs.value_.myString < rhs.value_.myString;
    default:
      return false;
  }
}

void swap(MyUnion& a, MyUnion& b) {
  MyUnion temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template void MyUnion::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MyUnion::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MyUnion::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MyUnion::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MyUnion::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::MyException>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::MyException>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

const char* MyException::__fbthrift_cpp2_gen_thrift_uri() {
  return "facebook.com/thrift/compiler/test/fixtures/any/MyException";
}

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
MyException::MyException(const MyException&) = default;
MyException& MyException::operator=(const MyException&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
MyException::MyException() {
}

THRIFT_IGNORE_ISSET_USE_WARNING_END

MyException::~MyException() {}

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
MyException::MyException(MyException&& other) noexcept  :
    myString(std::move(other.myString)),
    __isset(other.__isset) {}
MyException& MyException::operator=(FOLLY_MAYBE_UNUSED MyException&& other) noexcept {
    this->myString = std::move(other.myString);
    __isset = other.__isset;
    return *this;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END


THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
MyException::MyException(apache::thrift::FragileConstructor, ::std::string myString__arg) :
    myString(std::move(myString__arg)) {
  __isset.__fbthrift_set(folly::index_constant<0>(), true);
}
THRIFT_IGNORE_ISSET_USE_WARNING_END

void MyException::__clear() {
  // clear all fields
  this->myString = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset = {};
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

bool MyException::operator==(const MyException& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.myString_ref() == rhs.myString_ref())) {
    return false;
  }
  return true;
}

bool MyException::operator<(const MyException& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.myString_ref() == rhs.myString_ref())) {
    return lhs.myString_ref() < rhs.myString_ref();
  }
  return false;
}


void swap(MyException& a, MyException& b) {
  using ::std::swap;
  swap(a.myString_ref().value(), b.myString_ref().value());
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  swap(a.__isset, b.__isset);
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

template void MyException::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MyException::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MyException::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MyException::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MyException::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyException::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyException::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyException::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2
