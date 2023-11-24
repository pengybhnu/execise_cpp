
project(brpct)
find_package(brpc)


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
 ${CMAKE_SOURCE_DIR}/src/brpct/http.pb.cc)
 target_include_directories(http_server2 PRIVATE $<BUILD_INTERFACE:${brpc_BINARY_DIR}>/output/include)

target_link_libraries(http_server2 brpc-static CONAN_PKG::protobuf 
    CONAN_PKG::gflags
    CONAN_PKG::openssl
    CONAN_PKG::leveldb
)