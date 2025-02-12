cmake_minimum_required(VERSION 3.23)
project(substring_lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# add library
add_library(substring_lib STATIC
        src/substring_lib.cpp
        src/algorithms/kmp.cpp
)
target_include_directories(substring_lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithms
        ${CMAKE_CURRENT_SOURCE_DIR}/include)


# add tests
set(TEST_NAME ${PROJECT_NAME}_tests)
add_executable(${TEST_NAME}
        test/algorithms/doctest_main.cpp
        test/algorithms/test_kmp.cpp
)
target_link_libraries(${TEST_NAME} PRIVATE
        substring_lib
)

enable_testing()

add_test(
  NAME ${TEST_NAME}
  COMMAND $<TARGET_FILE:${TEST_NAME}>
)
