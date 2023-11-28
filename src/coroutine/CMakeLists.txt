cmake_minimum_required(VERSION 3.22)
project(coroutine)

add_executable(basec)
target_sources(basec PUBLIC ${CMAKE_SOURCE_DIR}/src/coroutine/basec.cpp)
target_compile_features(basec PRIVATE  cxx_std_20)
target_link_libraries(basec )


add_executable(coroutineb)
target_sources(coroutineb PUBLIC ${CMAKE_SOURCE_DIR}/src/coroutine/coroutineb.cpp)
target_compile_features(coroutineb PRIVATE  cxx_std_20)
target_link_libraries(coroutineb )

add_executable(coresum)
target_sources(coresum PUBLIC ${CMAKE_SOURCE_DIR}/src/coroutine/coro_resume.cpp)
target_compile_features(coresum PRIVATE  cxx_std_20)
target_link_libraries(coresum )

add_executable(asio_co)
target_sources(asio_co PUBLIC ${CMAKE_SOURCE_DIR}/src/coroutine/asio_server.cpp)
target_compile_features(asio_co PRIVATE  cxx_std_20)
target_link_libraries(asio_co CONAN_PKG::boost)