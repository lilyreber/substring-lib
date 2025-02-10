cmake_minimum_required(VERSION 3.23)
project(substring_lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_library(substring_lib STATIC
        src/substring_lib.cpp
        src/algorithms/kmp.cpp
        src/algorithms/boyer-moore.cpp
        src/algorithms/z_algorithm.cpp
)
target_include_directories(substring_lib PUBLIC
        include/algorithms
        include)

add_executable(substring_experimental
        test/experimental/benchmark.cpp
)
target_link_libraries(substring_experimental PRIVATE
        substring_lib
)

set(TEST_SOURCES
    test/algorithms/test_kmp.cpp
    test/algorithms/test_z_algorithm.cpp
)

foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME}
        test/algorithms/doctest_main.cpp
        ${TEST_SOURCE}
    )
    target_link_libraries(${TEST_NAME} PRIVATE substring_lib)
    add_test(
        NAME ${TEST_NAME}
        COMMAND $<TARGET_FILE:${TEST_NAME}>
    )
endforeach()

enable_testing()
