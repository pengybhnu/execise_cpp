cmake_minimum_required(VERSION 3.22)
project(container)


add_executable(eraset)
target_sources(eraset PUBLIC ${CMAKE_SOURCE_DIR}/src/container/eraset.cpp)
target_include_directories(eraset PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_options(eraset PRIVATE "-std=c++20")
target_link_libraries(eraset CONAN_PKG::boost)

# find_library(vsomeip)
find_package(vsomeip)
add_executable(vsomecl)
# build/_deps/vsomeip-src/interface/vsomeip
target_include_directories(vsomecl PRIVATE ${CMAKE_SOURCE_DIR}/build/_deps/vsomeip-src/interface)
target_sources(vsomecl PUBLIC ${CMAKE_SOURCE_DIR}/src/container/vsomecl.cpp)
target_link_libraries(vsomecl vsomeip3)