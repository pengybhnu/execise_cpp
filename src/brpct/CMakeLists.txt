
project(brpct)
find_package(brpc)

SET(PROTOC_BIN ${CONAN_BIN_DIRS_PROTOBUF}/protoc)
SET(PROTO_GRPC_BIN ${CONAN_BIN_DIRS_GRPC}/grpc_cpp_plugin)
SET(SOURCES_ABS_PATH  ${CMAKE_SOURCE_DIR}/src/brpct)
SET(PROTO_GEN_DIR  ${CMAKE_SOURCE_DIR}/src/brpct)
file(GLOB_RECURSE PROTO_LIST "${SOURCES_ABS_PATH}/*.proto")
message("------------------------>>>")
message(${SOURCES_ABS_PATH})

foreach(PROTO_FILE ${PROTO_LIST})
    message(${PROTO_FILE})

    file(RELATIVE_PATH PROTO_RELATIVE_PATH ${SOURCES_ABS_PATH} ${PROTO_FILE})
    set(PROTO_GEN_PATH "${PROTO_GEN_DIR}/${PROTO_RELATIVE_PATH}")
    message(${PROTO_RELATIVE_PATH})
   
    STRING(REGEX REPLACE "proto$" "pb.h" PROTO_HDR ${PROTO_GEN_PATH})
    STRING(REGEX REPLACE "proto$" "pb.cc" PROTO_SRC ${PROTO_GEN_PATH})
  

    list(APPEND PROTO_GEN_SRCS "${PROTO_HDR}")
    list(APPEND PROTO_GEN_SRCS "${PROTO_SRC}")
    list(APPEND PROTO_HDRs "${PROTO_HDR}")
    add_custom_command(
        OUTPUT ${PROTO_HDR} ${PROTO_SRC} 
        COMMAND ${PROTOC_BIN} -I ${SOURCES_ABS_PATH} --cpp_out ${SOURCES_ABS_PATH} 
         ${PROTO_FILE}
        COMMENT "Generating file from ${PROTO_FILE}"
        DEPENDS ${PROTO_FILE})

    # message(${PROTO_FILE})
endforeach()

add_executable(http_client2)
target_sources(http_client2 PUBLIC ${CMAKE_SOURCE_DIR}/src/brpct/http_client.cpp)
# target_include_directories(http_client PRIVATE ${brpc_SOURCE_DIR}/src)
target_include_directories(http_client2 PRIVATE $<BUILD_INTERFACE:${brpc_BINARY_DIR}>/output/include)

target_link_libraries(http_client2 PUBLIC
brpc-static
 CONAN_PKG::protobuf
CONAN_PKG::openssl
CONAN_PKG::leveldb
CONAN_PKG::gflags)

add_executable(http_server2)
target_sources(http_server2 PUBLIC ${CMAKE_SOURCE_DIR}/src/brpct/http_server.cpp
 ${PROTO_GEN_SRCS}
 )
 target_include_directories(http_server2 PRIVATE $<BUILD_INTERFACE:${brpc_BINARY_DIR}>/output/include)

target_link_libraries(http_server2 
    brpc-static 
    CONAN_PKG::protobuf 
    CONAN_PKG::gflags
    CONAN_PKG::openssl
    CONAN_PKG::leveldb
)

add_executable(conv)
target_sources(conv PUBLIC ${CMAKE_SOURCE_DIR}/src/brpct/conv.cpp   ${PROTO_GEN_SRCS})
target_link_libraries(conv CONAN_PKG::protobuf)