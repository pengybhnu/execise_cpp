cmake_minimum_required(VERSION 3.22)
project(boost)

add_executable(boostflat)
target_sources(boostflat PUBLIC ${CMAKE_SOURCE_DIR}/src/boost/currenthash.cpp)
target_compile_options(boostflat PRIVATE "-std=c++20")
target_link_libraries(boostflat ${CONAN_BOOST})


add_executable(syncontainer)
target_sources(syncontainer PUBLIC ${CMAKE_SOURCE_DIR}/src/boost/syncont.cpp)
target_link_libraries(syncontainer ${CONAN_LIBS_BOOST} ${CONAN_LIBS_FMT} pthread)

add_executable(readtest)
target_sources(readtest PUBLIC ${CMAKE_SOURCE_DIR}/src/boost/read.cpp)
target_compile_options(readtest PRIVATE "-std=c++17")

target_link_libraries(readtest ${CONAN_LIBS_REPLXX} pthread)