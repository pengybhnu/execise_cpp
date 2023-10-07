
cmake_minimum_required(VERSION 3.22)
project(simple)




add_executable(client)
target_sources(client PUBLIC ${PROJECT_SOURCE_DIR}/client.cpp)
target_include_directories(client PRIVATE ${PROJECT_SOURCE_DIR})
target_compile_features(client PUBLIC cxx_std_20)
target_link_libraries(client ${CONAN_LIBS} )

add_executable(server)
target_sources(server PUBLIC ${PROJECT_SOURCE_DIR}/server.cpp)
target_include_directories(server PRIVATE ${PROJECT_SOURCE_DIR})
target_compile_features(server PUBLIC cxx_std_20)
target_link_libraries(server ${CONAN_LIBS} )