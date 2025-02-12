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
set(TEST_SOURCES
        test/algorithms/test_kmp.cpp
        )

foreach (TEST_SOURCE ${TEST_SOURCES})
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
endforeach ()

enable_testing()