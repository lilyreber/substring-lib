cmake_minimum_required(VERSION 3.23)
project(substring_lib)

set(CMAKE_CXX_STANDARD 14)
enable_testing()

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(substring_lib src/substring_lib.cpp)

#add_executable(substring_experimental test/experimental/benchmark.cpp)
add_executable(substring_test test/algorithms/test_kmp.cpp)

target_link_libraries(substring_test PRIVATE GTest::GTest GTest::Main)

add_test(NAME ExampleTest COMMAND substring_test)