cmake_minimum_required(VERSION 3.23)
project(substring_lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include/algorithms include)

add_library(substring_lib STATIC
        src/substring_lib.cpp
        src/algorithms/kmp.cpp
)

add_executable(substring_experimental
        test/experimental/benchmark.cpp
)
target_link_libraries(substring_experimental PRIVATE
        substring_lib
)

set(TEST_NAME ${PROJECT_NAME}_tests)
add_executable(${TEST_NAME}
        test/algorithms/doctest_main.cpp
        test/algorithms/test_kmp.cpp
)
target_link_libraries(${TEST_NAME} PRIVATE
        substring_lib
)
