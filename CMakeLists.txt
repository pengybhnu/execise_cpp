cmake_minimum_required(VERSION 3.27)
project(libjoy)
# set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
# set(CMAKE_EXPERIMENTAL_CXX_SCANDEP_SOURCE "") 
# set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "aa1f7df0-828a-4fcd-9afc-2dc80491aca7") 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CONAN_DISABLE_CHECK_COMPILER ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_SCAN_FOR_MODULES ON)

#   include(${CMAKE_BINARY_DIR}/conan.cmake)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

# conan_cmake_run(
#     REQUIRES
#     ${${PROJECT_NAME}_CONAN_REQUIRES}
#     OPTIONS
#     ${${PROJECT_NAME}_CONAN_OPTIONS}
#     BASIC_SETUP
#     CMAKE_TARGETS # Individual targets to link to
#     BUILD
#     missing
# )
# option(ENABLE_CONAN "Enable the Conan package manager for this project." OFF)
# include(cmake/Conan.cmake)
conan_basic_setup(TARGETS)

# conan_basic_setup()
# include(cmake/CPM.cmake)
# add_executable(taskflowtest)
# target_sources(taskflowtest PUBLIC src/taskflowtest.cpp)
# target_compile_options(taskflowtest PRIVATE "-std=c++20")

# target_link_libraries(taskflowtest ${CONAN_LIBS_TASKFLOW})

# add_executable(fmtshow)
# target_sources(fmtshow PUBLIC src/fmtshow.cpp)
# target_compile_options(fmtshow PRIVATE "-std=c++20")
# target_link_libraries(fmtshow ${CONAN_LIBS_FMT})

# add_executable(typecheck)
# target_sources(typecheck PUBLIC src/checktype.cpp)
# target_compile_options(typecheck PRIVATE "-std=c++20")
# target_link_libraries(typecheck ${CONAN_LIBS})

# add_executable(tomlcfg)
# target_sources(tomlcfg PUBLIC src/tomlcfg.cpp)
# target_compile_options(tomlcfg PRIVATE "-std=c++2b")
# target_link_libraries(tomlcfg ${CONAN_LIBS})


# add_executable(rotateseg)
# target_sources(rotateseg PUBLIC src/rotation.cpp)
# target_compile_options(rotateseg PRIVATE "-std=c++20")
# target_link_libraries(rotateseg ${CONAN_LIBS})
# set(HEADS "da")
file(GLOB SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/base/*.cpp)
message(STATUS "${SOURCE_FILES}")
# install(FILES ${SOURCE_FILES} DESTINATION include/libjoy)
add_executable(breakt)
target_sources(breakt PUBLIC src/breakpadt.cpp)
target_compile_options(breakt PUBLIC "-g")
target_link_libraries(breakt CONAN_PKG::breakpad)

# find_library(stdexec REQUIRED  NAMES stdexec PATHS /usr/local/lib/cmake)
# /usr/local/lib/cmake/stdexec

include(cmake/CPM.cmake)
CPMAddPackage("gh:COVESA/vsomeip#3.3.0")
CPMAddPackage("gh:apache/brpc#1.7.0")
# CPMAddPackage("gh:alibaba/async_simple#1.2")
# https://github.com/apache/brpc
find_package(vsomeip)
message(${vsomeip_SOURCE_DIR})
message(${brpc_SOURCE_DIR})

add_subdirectory(src)

set(CMAKE_CXX_STANDARD 20)

# file(WRITE foo.h
# "class foo {
# foo();
# ~foo();
# void helloworld();
# };"
# )

# file(WRITE foo.cxx
# [=[
# #include "foo.h"
# #include <iostream>
# foo::foo() = default;
# foo::~foo() = default;
# void foo::helloworld() { std::cout << "hello world\n"; }
# ]=]
# )

# file(WRITE main.cxx
# [=[
# #include "foo.h"

# int main()
# {
#   foo f;
#   f.helloworld();
#   return 0;
# }
# ]=]
# )

# add_library(foo)
# target_sources(foo
#   PUBLIC
#     FILE_SET cxx_modules TYPE CXX_MODULES FILES
#     foo.cxx
# )
# add_executable(hello main.cxx)