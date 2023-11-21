cmake_minimum_required(VERSION 3.22)
project(boost)

add_executable(boostflat)
target_sources(boostflat PUBLIC ${CMAKE_SOURCE_DIR}/src/boost/currenthash.cpp)
target_compile_options(boostflat PRIVATE "-std=c++20")
target_link_libraries(boostflat CONAN_PKG::boost)


add_executable(syncontainer)
target_sources(syncontainer PUBLIC ${CMAKE_SOURCE_DIR}/src/boost/syncont.cpp)
target_link_libraries(syncontainer CONAN_PKG::boost CONAN_PKG::folly)

add_executable(readtest)
target_sources(readtest PUBLIC ${CMAKE_SOURCE_DIR}/src/boost/read.cpp)
target_compile_options(readtest PRIVATE "-std=c++17")

target_link_libraries(readtest CONAN_PKG::replxx pthread)


add_executable(aserver)
target_sources(aserver PUBLIC ${CMAKE_SOURCE_DIR}/src/boost/aserver.cpp)
target_compile_options(aserver PRIVATE "-std=c++20")
target_link_libraries(aserver CONAN_PKG::boost)



add_executable(achannel)
target_sources(achannel PUBLIC ${CMAKE_SOURCE_DIR}/src/boost/achannel.cpp)
target_compile_options(achannel PRIVATE "-std=c++20")
target_link_libraries(achannel CONAN_PKG::boost)

add_executable(serializeb)
target_sources(serializeb PUBLIC ${CMAKE_SOURCE_DIR}/src/boost/serialize.cpp)
target_compile_options(serializeb PRIVATE "-std=c++20")
target_link_libraries(serializeb CONAN_PKG::boost)

add_executable(bgil)
target_sources(bgil PUBLIC ${CMAKE_SOURCE_DIR}/src/boost/bgil.cpp)
target_link_libraries(bgil CONAN_PKG::boost)


add_executable(bunits)
target_sources(bunits PUBLIC  ${CMAKE_SOURCE_DIR}/src/boost/bunit.cpp)
target_link_libraries(bunits CONAN_PKG::boost)

add_executable(tokens)
target_sources(tokens PUBLIC ${CMAKE_SOURCE_DIR}/src/boost/tokensizer.cpp)
target_link_libraries(tokens CONAN_PKG::boost
CONAN_PKG::fmt
)

add_executable(outcome)
target_sources(outcome PUBLIC ${CMAKE_SOURCE_DIR}/src/boost/outcome.cpp)
target_link_libraries(outcome 
    CONAN_PKG::boost
    CONAN_PKG::fmt
)

add_executable(lineinter)
target_sources(lineinter PUBLIC  ${CMAKE_SOURCE_DIR}/src/boost/lineinter.cpp)
target_link_libraries(lineinter CONAN_PKG::boost)


add_executable(futureb)
target_sources(futureb PUBLIC ${CMAKE_SOURCE_DIR}/src/boost/futureb.cpp)
target_link_libraries(futureb CONAN_PKG::boost)