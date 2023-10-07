cmake_minimum_required(VERSION 3.22)
project(coost)


add_executable(coflags)
target_sources(coflags PUBLIC ${CMAKE_SOURCE_DIR}/src/coost/flags.cpp)
target_compile_options(coflags PRIVATE "-std=c++20")
target_link_libraries(coflags co)