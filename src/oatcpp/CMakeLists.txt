
cmake_minimum_required(VERSION 3.22)
project(otacppt)

add_executable(otaproto)
target_sources(otaproto PUBLIC 
    ${PROJECT_SOURCE_DIR}/otaproto.cpp
    ${PROJECT_SOURCE_DIR}/point.pb.cc
    ${CMAKE_SOURCE_DIR}/include/oatpp-protobuf/reflection/DynamicObject.cpp
    ${CMAKE_SOURCE_DIR}/include/oatpp-protobuf/Object.cpp
    ${CMAKE_SOURCE_DIR}/include/oatpp-protobuf/reflection/Utils.cpp
)
target_include_directories(otaproto PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(otaproto PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_options(otaproto PRIVATE "-std=c++17")
target_link_libraries(otaproto PRIVATE CONAN_PKG::oatpp CONAN_PKG::fmt CONAN_PKG::protobuf)