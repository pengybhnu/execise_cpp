cmake_minimum_required(VERSION 3.22)
project(folly)

add_executable(syntype)
target_sources(syntype PUBLIC ${CMAKE_SOURCE_DIR}/src/folly/syntype.cpp)
target_compile_features(syntype PRIVATE cxx_std_20)
target_link_libraries(syntype PRIVATE ${CONAN_LIBS_BOOST} ${CONAN_LIBS_FOLLY} ${CONAN_LIBS_FMT} pthread)