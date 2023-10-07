cmake_minimum_required(VERSION 3.22)
project(base)

add_executable(blobdata)
target_sources(blobdata PUBLIC ${CMAKE_SOURCE_DIR}/src/base/sqliteorm.cpp)
target_link_libraries(blobdata ${CONAN_LIBS})

add_executable(boostvar)
target_sources(boostvar PUBLIC  ${CMAKE_SOURCE_DIR}/src/base/boostvariant.cpp)
target_link_libraries(boostvar ${CONAN_LIBS})

add_executable(varmatch)
target_sources(varmatch PUBLIC ${CMAKE_SOURCE_DIR}/src/base/variantmatch.cpp)
target_include_directories(varmatch PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_options(varmatch PRIVATE "-std=c++20")
target_link_libraries(varmatch ${CONAN_LIBS})

add_executable(stacktraceb)
target_sources(stacktraceb PUBLIC ${CMAKE_SOURCE_DIR}/src/base/stacktraceb.cpp)
set_target_properties(stacktraceb PROPERTIES ENABLE_EXPORTS ON)

# target_compile_options(stacktraceb PUBLIC "-fPIE" "-rdynamic" "-no-pie" "-fno-pie")
# target_compile_options()
# target_link_libraries(stacktraceb)
target_link_libraries(stacktraceb PUBLIC ${CONAN_LIBS_BOOST} pthread dl)


# add_executable(cppco)
# target_compile_options(cppco PRIVATE "-std=c++2b")

# target_sources(cppco PUBLIC ${CMAKE_SOURCE_DIR}/src/base/gen.cpp)
# target_link_libraries(cppco ${CONAN_LIBS})

# add_executable(rangeb)
# target_compile_options(varmatch PRIVATE "-std=c++2b")
# target_sources(rangeb PUBLIC  ${CMAKE_SOURCE_DIR}/src/base/rangeb.cpp)
# target_link_libraries(rangeb ${CONAN_LIBS})
