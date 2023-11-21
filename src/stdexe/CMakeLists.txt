cmake_minimum_required(VERSION 3.22)
project(stdexet)
add_executable(whenany)
target_sources(whenany PUBLIC ${CMAKE_SOURCE_DIR}/src/stdexe/whenany.cpp)
target_compile_features(whenany PRIVATE cxx_std_20)
target_link_libraries(whenany  
  CONAN_PKG::onetbb
  pthread)

add_executable(justs)
target_sources(justs PUBLIC ${CMAKE_SOURCE_DIR}/src/stdexe/justs.cpp)
target_compile_features(justs PRIVATE cxx_std_20)

target_link_libraries(justs )