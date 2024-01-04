cmake_minimum_required(VERSION 3.22)
project(base)

add_executable(blobdata)
target_sources(blobdata PUBLIC ${CMAKE_SOURCE_DIR}/src/base/sqliteorm.cpp)
target_link_libraries(blobdata CONAN_PKG::sqlite_orm)

add_executable(boostvar)
target_sources(boostvar PUBLIC  ${CMAKE_SOURCE_DIR}/src/base/boostvariant.cpp)
target_compile_options(boostvar PRIVATE "-std=c++20")
target_link_libraries(boostvar CONAN_PKG::boost)

add_executable(varmatch)
target_sources(varmatch PUBLIC ${CMAKE_SOURCE_DIR}/src/base/variantmatch.cpp)
target_include_directories(varmatch PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_options(varmatch PRIVATE "-std=c++20")
target_link_libraries(varmatch CONAN_PKG::fmt CONAN_PKG::boost CONAN_PKG::tl-expected  CONAN_PKG::expected-lite)

add_executable(stacktraceb)
target_sources(stacktraceb PUBLIC ${CMAKE_SOURCE_DIR}/src/base/stacktraceb.cpp)
# set_target_properties(stacktraceb PROPERTIES ENABLE_EXPORTS ON)

target_compile_options(stacktraceb PRIVATE "-fPIE" "-no-pie" "-fno-pie")
# target_compile_options()
# target_link_libraries(stacktraceb)
target_link_libraries(stacktraceb PUBLIC CONAN_PKG::boost pthread dl)


# add_executable(cppco)
# target_compile_options(cppco PRIVATE "-std=c++2b")

# target_sources(cppco PUBLIC ${CMAKE_SOURCE_DIR}/src/base/gen.cpp)
# target_link_libraries(cppco ${CONAN_LIBS})

# add_executable(rangeb)
# target_compile_options(varmatch PRIVATE "-std=c++2b")
# target_sources(rangeb PUBLIC  ${CMAKE_SOURCE_DIR}/src/base/rangeb.cpp)
# target_link_libraries(rangeb ${CONAN_LIBS})

add_executable(sharedptr)
target_sources(sharedptr PUBLIC ${CMAKE_SOURCE_DIR}/src/base/shared.cpp)
target_link_libraries(sharedptr CONAN_PKG::fmt)


add_executable(rangev)
target_sources(rangev PUBLIC ${CMAKE_SOURCE_DIR}/src/base/ranges.cpp)
target_link_libraries(rangev CONAN_PKG::range-v3 CONAN_PKG::fmt)

add_executable(spant)
target_sources(spant PUBLIC ${CMAKE_SOURCE_DIR}/src/base/spand.cpp   ${CMAKE_SOURCE_DIR}/src/base/point.pb.cc)
target_include_directories(spant PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_compile_features(spant PRIVATE  cxx_std_20)
target_link_libraries(spant
 CONAN_PKG::fmt
 CONAN_PKG::protobuf
 CONAN_PKG::span-lite
 CONAN_PKG::tcb-span
 )

add_executable(cerealt)
target_sources(cerealt PUBLIC ${CMAKE_SOURCE_DIR}/src/base/cerealt.cpp)
target_link_libraries(cerealt CONAN_PKG::cereal CONAN_PKG::fmt )


# CPMAddPackage(
#   NAME simple_match
#   GIT_REPOSITORY https://github.com/jbandela/simple_match.git
#   GIT_TAG a3ab17f3d98db302de68ad85ed399a42ae41889e
#   DOWNLOAD_ONLY True
# )
# if(simple_match_ADDED)
#   add_library(simple_match INTERFACE IMPORTED)
#   target_include_directories(simple_match SYSTEM INTERFACE "${simple_match_SOURCE_DIR}/include")
# endif()
# add_executable(simple_exe)
# target_sources(simple_exe PUBLIC ${CMAKE_SOURCE_DIR}/src/base/simple_exe.cpp)
# target_link_libraries(simple_exe simple_match)


# CPMAddPackage(
#   NAME stdexec
#   GIT_REPOSITORY https://github.com/NVIDIA/stdexec.git
#   GIT_TAG main
# #   DOWNLOAD_ONLY True
# )

# https://github.com/apache/brpc.git

# find_library(stdexec REQUREd)
# add_executable(stdexect)
# target_sources(stdexect PUBLIC ${CMAKE_SOURCE_DIR}/src/base/stdexec.cpp)
# target_compile_options(stdexect PRIVATE "-std=c++20")
# target_include_directories(stdexect PUBLIC  "${stdexec_SOURCE_DIR}/include")
# target_link_libraries(stdexect PUBLIC 
# stdexec 

# ${CONAN_LIBS_FMT})


# CPMAddPackage(
#   NAME brpc
#   GIT_REPOSITORY https://github.com/apache/brpc.git
#   GIT_TAG 1.6.1
# )

add_executable(serdet)
target_sources(serdet PUBLIC ${CMAKE_SOURCE_DIR}/src/base/serdep.cpp)
target_compile_features(serdet PRIVATE  cxx_std_20)
target_link_libraries(serdet CONAN_PKG::serdepp)

add_executable(tloptional)
target_sources(tloptional PUBLIC ${CMAKE_SOURCE_DIR}/src/base/tloptional.cpp)
target_include_directories(tloptional PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_features(tloptional PRIVATE  cxx_std_23)
target_link_libraries(tloptional CONAN_PKG::tl-optional CONAN_PKG::fmt)


add_executable(imageteset)
target_sources(imageteset PUBLIC ${CMAKE_SOURCE_DIR}/src/base/imagetest.cpp)
target_link_libraries(imageteset CONAN_PKG::opencv)

add_executable(mpunits)
target_sources(mpunits PUBLIC ${CMAKE_SOURCE_DIR}/src/base/mpunits.cpp)
target_compile_features(mpunits PRIVATE  cxx_std_20)
target_link_libraries(mpunits CONAN_PKG::mp-units)

add_executable(mdspandt)
target_sources(mdspandt PUBLIC ${CMAKE_SOURCE_DIR}/src/base/mdspand.cpp)
target_compile_features(mdspandt PRIVATE  cxx_std_20)
target_link_libraries(mdspandt CONAN_PKG::mdspan)

add_executable(generate)
target_sources(generate PUBLIC ${CMAKE_SOURCE_DIR}/src/base/generate.cpp)
target_compile_features(generate PUBLIC  cxx_std_20)
target_link_libraries(generate )

add_executable(basenot)
target_sources(basenot PUBLIC ${CMAKE_SOURCE_DIR}/src/base/basenot.cpp)
target_link_libraries(basenot CONAN_PKG::fmt)

add_executable(memoryt)
target_sources(memoryt PUBLIC ${CMAKE_SOURCE_DIR}/src/base/tcmall.cpp)
target_link_libraries(memoryt)

add_executable(pimpl)
target_include_directories(pimpl PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_sources(pimpl PUBLIC
${CMAKE_SOURCE_DIR}/src/base/ifmain.cc
${CMAKE_SOURCE_DIR}/src/base/if.cc 
# ${CMAKE_SOURCE_DIR}/src/base/imp.cc
)
target_link_libraries(pimpl)

# src/base/httpserverbase.cpp
add_executable(httpser)
target_sources(httpser PUBLIC ${CMAKE_SOURCE_DIR}/src/base/httpserverbase.cpp)
target_link_libraries(httpser CONAN_PKG::cpp-httplib)