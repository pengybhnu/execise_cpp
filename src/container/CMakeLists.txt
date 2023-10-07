cmake_minimum_required(VERSION 3.22)
project(container)


add_executable(eraset)
target_sources(eraset PUBLIC ${CMAKE_SOURCE_DIR}/src/container/eraset.cpp)
target_include_directories(eraset PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_options(eraset PRIVATE "-std=c++20")
target_link_libraries(eraset ${CONAN_LIBS})

