
cmake_minimum_required(VERSION 3.22)
project(libcoro_test)




add_executable(catch2t)
target_sources(catch2t PUBLIC ${PROJECT_SOURCE_DIR}/fbstringt.cpp)
target_compile_features(catch2t PRIVATE cxx_std_20)
target_link_libraries(catch2t ${CONAN_LIBS_FOLLY} ${CONAN_LIBS_FMT} ${CONAN_LIBS_CATCH2})

# add_executable(cathtest)
# target_sources(cathtest PRIVATE ${PROJECT_SOURCE_DIR}/factest.cpp)
# target_compile_features(cathtest PRIVATE cxx_std_20)
# target_link_libraries(cathtest PRIVATE ${CONAN_LIBS_CATCH2})