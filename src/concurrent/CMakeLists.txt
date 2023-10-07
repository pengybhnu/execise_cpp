cmake_minimum_required(VERSION 3.22)
project(concurrent)


add_executable(subtask)
target_sources(subtask PUBLIC ${PROJECT_SOURCE_DIR}/tasksub.cpp)
target_include_directories(subtask PUBLIC  /usr/local/include/concurrencpp-0.1.7)
target_compile_options(subtask PRIVATE "-std=c++20")
target_link_libraries(subtask concurrencpp)


add_executable(pooltask)
target_sources(pooltask PUBLIC ${PROJECT_SOURCE_DIR}/threadpool.cpp)
target_include_directories(pooltask PUBLIC  /usr/local/include/concurrencpp-0.1.7)
target_compile_options(pooltask PRIVATE "-std=c++20")
target_link_libraries(pooltask concurrencpp)

add_executable(corotask)
target_sources(corotask PUBLIC ${PROJECT_SOURCE_DIR}/corotask.cpp)
target_compile_options(corotask PRIVATE "-std=c++20")
target_link_libraries(corotask ${CONAN_LIBS})


add_executable(evencoro)
target_compile_options(evencoro PRIVATE "-std=c++20")
target_sources(evencoro PUBLIC ${PROJECT_SOURCE_DIR}/libcoroevent.cpp)
target_link_libraries(evencoro ${CONAN_LIBS})

add_executable(generator)
target_compile_options(generator PRIVATE "-std=c++20")
target_sources(generator PRIVATE ${PROJECT_SOURCE_DIR}/generator.cpp)
target_link_libraries(generator ${CONAN_LIBS})

add_executable(httpcoro)
target_compile_options(httpcoro PRIVATE "-std=c++20")
target_sources(httpcoro PUBLIC ${PROJECT_SOURCE_DIR}/httprun.cpp)
target_link_libraries(httpcoro ${CONAN_LIBS})

add_executable(coromutex)
target_compile_options(coromutex PRIVATE "-std=c++20")
target_sources(coromutex PUBLIC ${PROJECT_SOURCE_DIR}/coromutex.cpp)
target_link_libraries(coromutex ${CONAN_LIBS})
