// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: point.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_point_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_point_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021009 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_point_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_point_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_point_2eproto;
namespace dispatch {
class Geo;
struct GeoDefaultTypeInternal;
extern GeoDefaultTypeInternal _Geo_default_instance_;
class Point;
struct PointDefaultTypeInternal;
extern PointDefaultTypeInternal _Point_default_instance_;
}  // namespace dispatch
PROTOBUF_NAMESPACE_OPEN
template<> ::dispatch::Geo* Arena::CreateMaybeMessage<::dispatch::Geo>(Arena*);
template<> ::dispatch::Point* Arena::CreateMaybeMessage<::dispatch::Point>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace dispatch {

// ===================================================================

class Geo final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:dispatch.Geo) */ {
 public:
  inline Geo() : Geo(nullptr) {}
  ~Geo() override;
  explicit PROTOBUF_CONSTEXPR Geo(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Geo(const Geo& from);
  Geo(Geo&& from) noexcept
    : Geo() {
    *this = ::std::move(from);
  }

  inline Geo& operator=(const Geo& from) {
    CopyFrom(from);
    return *this;
  }
  inline Geo& operator=(Geo&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Geo& default_instance() {
    return *internal_default_instance();
  }
  static inline const Geo* internal_default_instance() {
    return reinterpret_cast<const Geo*>(
               &_Geo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Geo& a, Geo& b) {
    a.Swap(&b);
  }
  inline void Swap(Geo* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Geo* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Geo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Geo>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Geo& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Geo& from) {
    Geo::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Geo* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "dispatch.Geo";
  }
  protected:
  explicit Geo(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kPointFieldNumber = 2,
  };
  // string name = 1;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // .dispatch.Point point = 2;
  bool has_point() const;
  private:
  bool _internal_has_point() const;
  public:
  void clear_point();
  const ::dispatch::Point& point() const;
  PROTOBUF_NODISCARD ::dispatch::Point* release_point();
  ::dispatch::Point* mutable_point();
  void set_allocated_point(::dispatch::Point* point);
  private:
  const ::dispatch::Point& _internal_point() const;
  ::dispatch::Point* _internal_mutable_point();
  public:
  void unsafe_arena_set_allocated_point(
      ::dispatch::Point* point);
  ::dispatch::Point* unsafe_arena_release_point();

  // @@protoc_insertion_point(class_scope:dispatch.Geo)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
    ::dispatch::Point* point_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_point_2eproto;
};
// -------------------------------------------------------------------

class Point final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:dispatch.Point) */ {
 public:
  inline Point() : Point(nullptr) {}
  ~Point() override;
  explicit PROTOBUF_CONSTEXPR Point(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Point(const Point& from);
  Point(Point&& from) noexcept
    : Point() {
    *this = ::std::move(from);
  }

  inline Point& operator=(const Point& from) {
    CopyFrom(from);
    return *this;
  }
  inline Point& operator=(Point&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Point& default_instance() {
    return *internal_default_instance();
  }
  static inline const Point* internal_default_instance() {
    return reinterpret_cast<const Point*>(
               &_Point_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Point& a, Point& b) {
    a.Swap(&b);
  }
  inline void Swap(Point* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Point* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Point* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Point>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Point& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Point& from) {
    Point::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Point* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "dispatch.Point";
  }
  protected:
  explicit Point(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kYFieldNumber = 2,
  };
  // double x = 1;
  void clear_x();
  double x() const;
  void set_x(double value);
  private:
  double _internal_x() const;
  void _internal_set_x(double value);
  public:

  // double y = 2;
  void clear_y();
  double y() const;
  void set_y(double value);
  private:
  double _internal_y() const;
  void _internal_set_y(double value);
  public:

  // @@protoc_insertion_point(class_scope:dispatch.Point)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    double x_;
    double y_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_point_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Geo

// string name = 1;
inline void Geo::clear_name() {
  _impl_.name_.ClearToEmpty();
}
inline const std::string& Geo::name() const {
  // @@protoc_insertion_point(field_get:dispatch.Geo.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Geo::set_name(ArgT0&& arg0, ArgT... args) {
 
 _impl_.name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:dispatch.Geo.name)
}
inline std::string* Geo::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:dispatch.Geo.name)
  return _s;
}
inline const std::string& Geo::_internal_name() const {
  return _impl_.name_.Get();
}
inline void Geo::_internal_set_name(const std::string& value) {
  
  _impl_.name_.Set(value, GetArenaForAllocation());
}
inline std::string* Geo::_internal_mutable_name() {
  
  return _impl_.name_.Mutable(GetArenaForAllocation());
}
inline std::string* Geo::release_name() {
  // @@protoc_insertion_point(field_release:dispatch.Geo.name)
  return _impl_.name_.Release();
}
inline void Geo::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  _impl_.name_.SetAllocated(name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:dispatch.Geo.name)
}

// .dispatch.Point point = 2;
inline bool Geo::_internal_has_point() const {
  return this != internal_default_instance() && _impl_.point_ != nullptr;
}
inline bool Geo::has_point() const {
  return _internal_has_point();
}
inline void Geo::clear_point() {
  if (GetArenaForAllocation() == nullptr && _impl_.point_ != nullptr) {
    delete _impl_.point_;
  }
  _impl_.point_ = nullptr;
}
inline const ::dispatch::Point& Geo::_internal_point() const {
  const ::dispatch::Point* p = _impl_.point_;
  return p != nullptr ? *p : reinterpret_cast<const ::dispatch::Point&>(
      ::dispatch::_Point_default_instance_);
}
inline const ::dispatch::Point& Geo::point() const {
  // @@protoc_insertion_point(field_get:dispatch.Geo.point)
  return _internal_point();
}
inline void Geo::unsafe_arena_set_allocated_point(
    ::dispatch::Point* point) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.point_);
  }
  _impl_.point_ = point;
  if (point) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:dispatch.Geo.point)
}
inline ::dispatch::Point* Geo::release_point() {
  
  ::dispatch::Point* temp = _impl_.point_;
  _impl_.point_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::dispatch::Point* Geo::unsafe_arena_release_point() {
  // @@protoc_insertion_point(field_release:dispatch.Geo.point)
  
  ::dispatch::Point* temp = _impl_.point_;
  _impl_.point_ = nullptr;
  return temp;
}
inline ::dispatch::Point* Geo::_internal_mutable_point() {
  
  if (_impl_.point_ == nullptr) {
    auto* p = CreateMaybeMessage<::dispatch::Point>(GetArenaForAllocation());
    _impl_.point_ = p;
  }
  return _impl_.point_;
}
inline ::dispatch::Point* Geo::mutable_point() {
  ::dispatch::Point* _msg = _internal_mutable_point();
  // @@protoc_insertion_point(field_mutable:dispatch.Geo.point)
  return _msg;
}
inline void Geo::set_allocated_point(::dispatch::Point* point) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete _impl_.point_;
  }
  if (point) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(point);
    if (message_arena != submessage_arena) {
      point = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, point, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.point_ = point;
  // @@protoc_insertion_point(field_set_allocated:dispatch.Geo.point)
}

// -------------------------------------------------------------------

// Point

// double x = 1;
inline void Point::clear_x() {
  _impl_.x_ = 0;
}
inline double Point::_internal_x() const {
  return _impl_.x_;
}
inline double Point::x() const {
  // @@protoc_insertion_point(field_get:dispatch.Point.x)
  return _internal_x();
}
inline void Point::_internal_set_x(double value) {
  
  _impl_.x_ = value;
}
inline void Point::set_x(double value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:dispatch.Point.x)
}

// double y = 2;
inline void Point::clear_y() {
  _impl_.y_ = 0;
}
inline double Point::_internal_y() const {
  return _impl_.y_;
}
inline double Point::y() const {
  // @@protoc_insertion_point(field_get:dispatch.Point.y)
  return _internal_y();
}
inline void Point::_internal_set_y(double value) {
  
  _impl_.y_ = value;
}
inline void Point::set_y(double value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:dispatch.Point.y)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace dispatch

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_point_2eproto
