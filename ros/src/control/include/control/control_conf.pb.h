// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: control_conf.proto

#ifndef PROTOBUF_INCLUDED_control_5fconf_2eproto
#define PROTOBUF_INCLUDED_control_5fconf_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3006001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "lon_controller_conf.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_control_5fconf_2eproto

// Internal implementation detail -- do not use these members.
struct TableStruct_control_5fconf_2eproto {
  static const ::google::protobuf::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors_control_5fconf_2eproto();
namespace autocar {
namespace control {
class ControlConf;
class ControlConfDefaultTypeInternal;
extern ControlConfDefaultTypeInternal _ControlConf_default_instance_;
}  // namespace control
}  // namespace autocar
namespace google {
namespace protobuf {
template<> ::autocar::control::ControlConf* Arena::CreateMaybeMessage<::autocar::control::ControlConf>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace autocar {
namespace control {

// ===================================================================

class ControlConf : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:autocar.control.ControlConf) */ {
 public:
  ControlConf();
  virtual ~ControlConf();

  ControlConf(const ControlConf& from);

  inline ControlConf& operator=(const ControlConf& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ControlConf(ControlConf&& from) noexcept
    : ControlConf() {
    *this = ::std::move(from);
  }

  inline ControlConf& operator=(ControlConf&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const ControlConf& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ControlConf* internal_default_instance() {
    return reinterpret_cast<const ControlConf*>(
               &_ControlConf_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(ControlConf* other);
  friend void swap(ControlConf& a, ControlConf& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ControlConf* New() const final {
    return CreateMaybeMessage<ControlConf>(NULL);
  }

  ControlConf* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ControlConf>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ControlConf& from);
  void MergeFrom(const ControlConf& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
  ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
  #else
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ControlConf* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .autocar.control.LonControllerConf lon_controller_conf = 1;
  bool has_lon_controller_conf() const;
  void clear_lon_controller_conf();
  static const int kLonControllerConfFieldNumber = 1;
  const ::autocar::control::LonControllerConf& lon_controller_conf() const;
  ::autocar::control::LonControllerConf* release_lon_controller_conf();
  ::autocar::control::LonControllerConf* mutable_lon_controller_conf();
  void set_allocated_lon_controller_conf(::autocar::control::LonControllerConf* lon_controller_conf);

  // @@protoc_insertion_point(class_scope:autocar.control.ControlConf)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::autocar::control::LonControllerConf* lon_controller_conf_;
  friend struct ::TableStruct_control_5fconf_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ControlConf

// optional .autocar.control.LonControllerConf lon_controller_conf = 1;
inline bool ControlConf::has_lon_controller_conf() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline const ::autocar::control::LonControllerConf& ControlConf::lon_controller_conf() const {
  const ::autocar::control::LonControllerConf* p = lon_controller_conf_;
  // @@protoc_insertion_point(field_get:autocar.control.ControlConf.lon_controller_conf)
  return p != NULL ? *p : *reinterpret_cast<const ::autocar::control::LonControllerConf*>(
      &::autocar::control::_LonControllerConf_default_instance_);
}
inline ::autocar::control::LonControllerConf* ControlConf::release_lon_controller_conf() {
  // @@protoc_insertion_point(field_release:autocar.control.ControlConf.lon_controller_conf)
  _has_bits_[0] &= ~0x00000001u;
  ::autocar::control::LonControllerConf* temp = lon_controller_conf_;
  lon_controller_conf_ = NULL;
  return temp;
}
inline ::autocar::control::LonControllerConf* ControlConf::mutable_lon_controller_conf() {
  _has_bits_[0] |= 0x00000001u;
  if (lon_controller_conf_ == NULL) {
    auto* p = CreateMaybeMessage<::autocar::control::LonControllerConf>(GetArenaNoVirtual());
    lon_controller_conf_ = p;
  }
  // @@protoc_insertion_point(field_mutable:autocar.control.ControlConf.lon_controller_conf)
  return lon_controller_conf_;
}
inline void ControlConf::set_allocated_lon_controller_conf(::autocar::control::LonControllerConf* lon_controller_conf) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(lon_controller_conf_);
  }
  if (lon_controller_conf) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      lon_controller_conf = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, lon_controller_conf, submessage_arena);
    }
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  lon_controller_conf_ = lon_controller_conf;
  // @@protoc_insertion_point(field_set_allocated:autocar.control.ControlConf.lon_controller_conf)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace control
}  // namespace autocar

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // PROTOBUF_INCLUDED_control_5fconf_2eproto
