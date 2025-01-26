cmake_minimum_required(VERSION 3.23)
project(substring_lib)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(include/algorithms include)

add_library(substring_lib STATIC src/substring_lib.cpp src/algorithms/kmp.cpp)

add_executable(substring_experimental test/experimental/benchmark.cpp)
target_link_libraries(substring_experimental PRIVATE substring_lib)


set(TEST_NAME ${PROJECT_NAME}_tests)
add_executable(${TEST_NAME} test/algorithms/test_kmp.cpp)
target_link_libraries(${TEST_NAME} PRIVATE gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})
