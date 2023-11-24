
cmake_minimum_required(VERSION 3.22)
project(simple)

add_executable(client)
target_sources(client PUBLIC ${PROJECT_SOURCE_DIR}/client.cpp)
target_include_directories(client PRIVATE ${async_simple_SOURCE_DIR})
target_compile_features(client PUBLIC cxx_std_20)
target_link_libraries(client  async_simple aio CONAN_PKG::asio )

add_executable(server)
target_sources(server PUBLIC ${PROJECT_SOURCE_DIR}/server.cpp)
target_include_directories(client PRIVATE ${async_simple_SOURCE_DIR})
target_compile_features(server PUBLIC cxx_std_20)
target_link_libraries(server async_simple CONAN_PKG::asio)

add_executable(stdexep)
target_sources(stdexep PUBLIC ${PROJECT_SOURCE_DIR}/stdexeh.cpp)
target_include_directories(client PRIVATE ${async_simple_SOURCE_DIR})
target_compile_features(stdexep PUBLIC cxx_std_20)
target_link_libraries(stdexep)


add_executable(stdpool)
target_sources(stdpool PUBLIC ${PROJECT_SOURCE_DIR}/stdpool.cpp)
target_compile_features(stdpool PUBLIC cxx_std_20)
target_link_libraries(stdpool)

add_executable(stdexebase)
target_sources(stdexebase PUBLIC ${PROJECT_SOURCE_DIR}/stdexebase.cpp)

target_compile_features(stdexebase PUBLIC cxx_std_20)
target_link_libraries(stdexebase)