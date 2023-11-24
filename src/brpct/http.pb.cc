// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: http.proto

#include "http.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace example {
PROTOBUF_CONSTEXPR HttpRequest::HttpRequest(
    ::_pbi::ConstantInitialized) {}
struct HttpRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR HttpRequestDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~HttpRequestDefaultTypeInternal() {}
  union {
    HttpRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 HttpRequestDefaultTypeInternal _HttpRequest_default_instance_;
PROTOBUF_CONSTEXPR HttpResponse::HttpResponse(
    ::_pbi::ConstantInitialized) {}
struct HttpResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR HttpResponseDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~HttpResponseDefaultTypeInternal() {}
  union {
    HttpResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 HttpResponseDefaultTypeInternal _HttpResponse_default_instance_;
}  // namespace example
static ::_pb::Metadata file_level_metadata_http_2eproto[2];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_http_2eproto = nullptr;
static const ::_pb::ServiceDescriptor* file_level_service_descriptors_http_2eproto[4];

const uint32_t TableStruct_http_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::example::HttpRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::example::HttpResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::example::HttpRequest)},
  { 6, -1, -1, sizeof(::example::HttpResponse)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::example::_HttpRequest_default_instance_._instance,
  &::example::_HttpResponse_default_instance_._instance,
};

const char descriptor_table_protodef_http_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\nhttp.proto\022\007example\"\r\n\013HttpRequest\"\016\n\014"
  "HttpResponse2\177\n\013HttpService\0223\n\004Echo\022\024.ex"
  "ample.HttpRequest\032\025.example.HttpResponse"
  "\022;\n\014EchoProtobuf\022\024.example.HttpRequest\032\025"
  ".example.HttpResponse2L\n\013FileService\022=\n\016"
  "default_method\022\024.example.HttpRequest\032\025.e"
  "xample.HttpResponse2\262\001\n\014QueueService\0224\n\005"
  "start\022\024.example.HttpRequest\032\025.example.Ht"
  "tpResponse\0223\n\004stop\022\024.example.HttpRequest"
  "\032\025.example.HttpResponse\0227\n\010getstats\022\024.ex"
  "ample.HttpRequest\032\025.example.HttpResponse"
  "2G\n\016HttpSSEService\0225\n\006stream\022\024.example.H"
  "ttpRequest\032\025.example.HttpResponseB\003\200\001\001"
  ;
static ::_pbi::once_flag descriptor_table_http_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_http_2eproto = {
    false, false, 518, descriptor_table_protodef_http_2eproto,
    "http.proto",
    &descriptor_table_http_2eproto_once, nullptr, 0, 2,
    schemas, file_default_instances, TableStruct_http_2eproto::offsets,
    file_level_metadata_http_2eproto, file_level_enum_descriptors_http_2eproto,
    file_level_service_descriptors_http_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_http_2eproto_getter() {
  return &descriptor_table_http_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_http_2eproto(&descriptor_table_http_2eproto);
namespace example {

// ===================================================================

class HttpRequest::_Internal {
 public:
};

HttpRequest::HttpRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase(arena, is_message_owned) {
  // @@protoc_insertion_point(arena_constructor:example.HttpRequest)
}
HttpRequest::HttpRequest(const HttpRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase() {
  HttpRequest* const _this = this; (void)_this;
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:example.HttpRequest)
}





const ::PROTOBUF_NAMESPACE_ID::Message::ClassData HttpRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::CopyImpl,
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::MergeImpl,
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*HttpRequest::GetClassData() const { return &_class_data_; }







::PROTOBUF_NAMESPACE_ID::Metadata HttpRequest::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_http_2eproto_getter, &descriptor_table_http_2eproto_once,
      file_level_metadata_http_2eproto[0]);
}

// ===================================================================

class HttpResponse::_Internal {
 public:
};

HttpResponse::HttpResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase(arena, is_message_owned) {
  // @@protoc_insertion_point(arena_constructor:example.HttpResponse)
}
HttpResponse::HttpResponse(const HttpResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase() {
  HttpResponse* const _this = this; (void)_this;
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:example.HttpResponse)
}





const ::PROTOBUF_NAMESPACE_ID::Message::ClassData HttpResponse::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::CopyImpl,
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::MergeImpl,
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*HttpResponse::GetClassData() const { return &_class_data_; }







::PROTOBUF_NAMESPACE_ID::Metadata HttpResponse::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_http_2eproto_getter, &descriptor_table_http_2eproto_once,
      file_level_metadata_http_2eproto[1]);
}

// ===================================================================

HttpService::~HttpService() {}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* HttpService::descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_http_2eproto);
  return file_level_service_descriptors_http_2eproto[0];
}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* HttpService::GetDescriptor() {
  return descriptor();
}

void HttpService::Echo(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::example::HttpRequest*,
                         ::example::HttpResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Echo() not implemented.");
  done->Run();
}

void HttpService::EchoProtobuf(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::example::HttpRequest*,
                         ::example::HttpResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method EchoProtobuf() not implemented.");
  done->Run();
}

void HttpService::CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                             ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                             const ::PROTOBUF_NAMESPACE_ID::Message* request,
                             ::PROTOBUF_NAMESPACE_ID::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), file_level_service_descriptors_http_2eproto[0]);
  switch(method->index()) {
    case 0:
      Echo(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::example::HttpRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::example::HttpResponse*>(
                 response),
             done);
      break;
    case 1:
      EchoProtobuf(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::example::HttpRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::example::HttpResponse*>(
                 response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& HttpService::GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::example::HttpRequest::default_instance();
    case 1:
      return ::example::HttpRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->input_type());
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& HttpService::GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::example::HttpResponse::default_instance();
    case 1:
      return ::example::HttpResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->output_type());
  }
}

HttpService_Stub::HttpService_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
HttpService_Stub::HttpService_Stub(
    ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
    ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::PROTOBUF_NAMESPACE_ID::Service::STUB_OWNS_CHANNEL) {}
HttpService_Stub::~HttpService_Stub() {
  if (owns_channel_) delete channel_;
}

void HttpService_Stub::Echo(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::example::HttpRequest* request,
                              ::example::HttpResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}
void HttpService_Stub::EchoProtobuf(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::example::HttpRequest* request,
                              ::example::HttpResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(1),
                       controller, request, response, done);
}
// ===================================================================

FileService::~FileService() {}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* FileService::descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_http_2eproto);
  return file_level_service_descriptors_http_2eproto[1];
}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* FileService::GetDescriptor() {
  return descriptor();
}

void FileService::default_method(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::example::HttpRequest*,
                         ::example::HttpResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method default_method() not implemented.");
  done->Run();
}

void FileService::CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                             ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                             const ::PROTOBUF_NAMESPACE_ID::Message* request,
                             ::PROTOBUF_NAMESPACE_ID::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), file_level_service_descriptors_http_2eproto[1]);
  switch(method->index()) {
    case 0:
      default_method(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::example::HttpRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::example::HttpResponse*>(
                 response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& FileService::GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::example::HttpRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->input_type());
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& FileService::GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::example::HttpResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->output_type());
  }
}

FileService_Stub::FileService_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
FileService_Stub::FileService_Stub(
    ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
    ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::PROTOBUF_NAMESPACE_ID::Service::STUB_OWNS_CHANNEL) {}
FileService_Stub::~FileService_Stub() {
  if (owns_channel_) delete channel_;
}

void FileService_Stub::default_method(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::example::HttpRequest* request,
                              ::example::HttpResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}
// ===================================================================

QueueService::~QueueService() {}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* QueueService::descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_http_2eproto);
  return file_level_service_descriptors_http_2eproto[2];
}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* QueueService::GetDescriptor() {
  return descriptor();
}

void QueueService::start(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::example::HttpRequest*,
                         ::example::HttpResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method start() not implemented.");
  done->Run();
}

void QueueService::stop(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::example::HttpRequest*,
                         ::example::HttpResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method stop() not implemented.");
  done->Run();
}

void QueueService::getstats(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::example::HttpRequest*,
                         ::example::HttpResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method getstats() not implemented.");
  done->Run();
}

void QueueService::CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                             ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                             const ::PROTOBUF_NAMESPACE_ID::Message* request,
                             ::PROTOBUF_NAMESPACE_ID::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), file_level_service_descriptors_http_2eproto[2]);
  switch(method->index()) {
    case 0:
      start(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::example::HttpRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::example::HttpResponse*>(
                 response),
             done);
      break;
    case 1:
      stop(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::example::HttpRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::example::HttpResponse*>(
                 response),
             done);
      break;
    case 2:
      getstats(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::example::HttpRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::example::HttpResponse*>(
                 response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& QueueService::GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::example::HttpRequest::default_instance();
    case 1:
      return ::example::HttpRequest::default_instance();
    case 2:
      return ::example::HttpRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->input_type());
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& QueueService::GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::example::HttpResponse::default_instance();
    case 1:
      return ::example::HttpResponse::default_instance();
    case 2:
      return ::example::HttpResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->output_type());
  }
}

QueueService_Stub::QueueService_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
QueueService_Stub::QueueService_Stub(
    ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
    ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::PROTOBUF_NAMESPACE_ID::Service::STUB_OWNS_CHANNEL) {}
QueueService_Stub::~QueueService_Stub() {
  if (owns_channel_) delete channel_;
}

void QueueService_Stub::start(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::example::HttpRequest* request,
                              ::example::HttpResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}
void QueueService_Stub::stop(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::example::HttpRequest* request,
                              ::example::HttpResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(1),
                       controller, request, response, done);
}
void QueueService_Stub::getstats(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::example::HttpRequest* request,
                              ::example::HttpResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(2),
                       controller, request, response, done);
}
// ===================================================================

HttpSSEService::~HttpSSEService() {}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* HttpSSEService::descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_http_2eproto);
  return file_level_service_descriptors_http_2eproto[3];
}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* HttpSSEService::GetDescriptor() {
  return descriptor();
}

void HttpSSEService::stream(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::example::HttpRequest*,
                         ::example::HttpResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method stream() not implemented.");
  done->Run();
}

void HttpSSEService::CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                             ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                             const ::PROTOBUF_NAMESPACE_ID::Message* request,
                             ::PROTOBUF_NAMESPACE_ID::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), file_level_service_descriptors_http_2eproto[3]);
  switch(method->index()) {
    case 0:
      stream(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::example::HttpRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::example::HttpResponse*>(
                 response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& HttpSSEService::GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::example::HttpRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->input_type());
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& HttpSSEService::GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::example::HttpResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->output_type());
  }
}

HttpSSEService_Stub::HttpSSEService_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
HttpSSEService_Stub::HttpSSEService_Stub(
    ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
    ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::PROTOBUF_NAMESPACE_ID::Service::STUB_OWNS_CHANNEL) {}
HttpSSEService_Stub::~HttpSSEService_Stub() {
  if (owns_channel_) delete channel_;
}

void HttpSSEService_Stub::stream(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::example::HttpRequest* request,
                              ::example::HttpResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace example
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::example::HttpRequest*
Arena::CreateMaybeMessage< ::example::HttpRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::example::HttpRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::example::HttpResponse*
Arena::CreateMaybeMessage< ::example::HttpResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::example::HttpResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
