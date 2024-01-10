
cmake_minimum_required(VERSION 3.27)
project(cerespro)

add_executable(baseca)
target_sources(baseca PUBLIC ${PROJECT_SOURCE_DIR}/baseca.cpp)
target_include_directories(baseca PRIVATE ${PROJECT_SOURCE_DIR})
target_compile_features(baseca PUBLIC cxx_std_20)
target_link_libraries(baseca CONAN_PKG::ceres-solver CONAN_PKG::glog CONAN_PKG::gflags)

add_executable(fitc)
target_sources(fitc PUBLIC ${PROJECT_SOURCE_DIR}/fitc.cpp)
target_include_directories(fitc PRIVATE ${PROJECT_SOURCE_DIR})
target_compile_features(fitc PUBLIC cxx_std_20)
target_link_libraries(fitc CONAN_PKG::ceres-solver CONAN_PKG::glog CONAN_PKG::gflags)


# add_executable(osqpb)
# target_sources(osqpb PUBLIC ${PROJECT_SOURCE_DIR}/osqpb.cpp)
# target_include_directories(osqpb PRIVATE ${PROJECT_SOURCE_DIR})
# target_compile_features(osqpb PUBLIC cxx_std_20)
# target_link_libraries(osqpb ${CONAN_LIBS} )

add_executable(cirfit)
target_sources(cirfit PUBLIC ${PROJECT_SOURCE_DIR}/cirfit.cpp)
target_include_directories(cirfit PRIVATE ${PROJECT_SOURCE_DIR})
target_compile_features(cirfit PUBLIC cxx_std_20)
target_link_libraries(cirfit CONAN_PKG::ceres-solver CONAN_PKG::glog CONAN_PKG::gflags)