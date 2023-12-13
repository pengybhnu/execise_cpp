cmake_minimum_required(VERSION 3.22)
project(folly)

add_executable(syntype)
target_sources(syntype PUBLIC ${CMAKE_SOURCE_DIR}/src/folly/syntype.cpp)
target_compile_features(syntype PRIVATE cxx_std_20)
target_link_libraries(syntype PRIVATE CONAN_PKG::folly CONAN_PKG::range-v3)

add_executable(datastruct)
target_sources(datastruct PUBLIC ${CMAKE_SOURCE_DIR}/src/folly/data_struct.cpp)
target_compile_features(datastruct PRIVATE cxx_std_20)
target_link_libraries(datastruct PRIVATE CONAN_PKG::folly)

add_executable(threadpool)
target_sources(threadpool PUBLIC ${CMAKE_SOURCE_DIR}/src/folly/threadpool.cpp)
target_compile_features(threadpool PRIVATE cxx_std_17)
# set_target_properties()
# target_link_options(threadpool PRIVATE "-s")
set_target_properties(threadpool PROPERTIES DEBUG_POSTFIX "-d" )
target_link_libraries(threadpool CONAN_PKG::folly)

add_executable(fiberf)
target_sources(fiberf PUBLIC ${CMAKE_SOURCE_DIR}/src/folly/filberf.cpp)
target_link_libraries(fiberf CONAN_PKG::folly )

add_executable(fiberapp)
target_sources(fiberapp PUBLIC ${CMAKE_SOURCE_DIR}/src/folly/fiberapp.cpp)
target_compile_features(fiberapp PRIVATE cxx_std_20)
target_link_libraries(fiberapp CONAN_PKG::folly )

add_executable(excutep)
target_sources(excutep PUBLIC ${CMAKE_SOURCE_DIR}/src/folly/excutep.cpp)
target_compile_features(excutep PRIVATE cxx_std_20)
target_link_libraries(excutep CONAN_PKG::folly )


add_executable(globalp)
target_sources(globalp PUBLIC ${CMAKE_SOURCE_DIR}/src/folly/globalp.cpp)
target_link_libraries(globalp CONAN_PKG::folly)


add_executable(collection)
target_sources(collection PUBLIC ${CMAKE_SOURCE_DIR}/src/folly/collection.cpp)
target_link_libraries(collection CONAN_PKG::folly)


add_executable(taskcore)
target_sources(taskcore PUBLIC ${CMAKE_SOURCE_DIR}/src/folly/taskcoro.cpp)
target_compile_features(taskcore PRIVATE cxx_std_20)
target_link_libraries(taskcore CONAN_PKG::folly)

add_executable(batonp)
target_sources(batonp PUBLIC ${CMAKE_SOURCE_DIR}/src/folly/batonp.cpp)
target_compile_features(batonp PRIVATE cxx_std_20)
target_link_libraries(batonp CONAN_PKG::folly)


