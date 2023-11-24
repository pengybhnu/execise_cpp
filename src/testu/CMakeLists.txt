
cmake_minimum_required(VERSION 3.22)
project(folly_test)




add_executable(catch2t)
target_sources(catch2t PUBLIC ${PROJECT_SOURCE_DIR}/fbstringt.cpp)
target_compile_features(catch2t PRIVATE cxx_std_20)
target_link_libraries(catch2t  CONAN_PKG::catch2  CONAN_PKG::folly)

# add_executable(cathtest)
# target_sources(cathtest PRIVATE ${PROJECT_SOURCE_DIR}/factest.cpp)
# target_compile_features(cathtest PRIVATE cxx_std_20)
# target_link_libraries(cathtest PRIVATE ${CONAN_LIBS_CATCH2})

add_executable(doctestp)
target_sources(doctestp PUBLIC ${PROJECT_SOURCE_DIR}/doctestf.cpp)
target_link_libraries(doctestp  CONAN_PKG::fmt  CONAN_PKG::doctest  CONAN_PKG::span-lite)


add_executable(doctest2f)
target_sources(doctest2f PUBLIC ${PROJECT_SOURCE_DIR}/doctest2f.cpp)
target_link_libraries(doctest2f CONAN_PKG::fmt  CONAN_PKG::doctest CONAN_PKG::fmt  CONAN_PKG::span-lite)