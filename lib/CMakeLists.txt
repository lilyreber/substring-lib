cmake_minimum_required(VERSION 3.23)
project(substring_lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-fsanitize=address,undefined)
add_link_options(-fsanitize=address,undefined)

add_library(substring_lib STATIC
        src/substring_lib.cpp
        src/algorithms/kmp.cpp
        src/algorithms/boyer_moore.cpp
        src/algorithms/z_algorithm.cpp
        src/algorithms/suffix_array.cpp
        src/algorithms/rabin_karp.cpp
        )
target_include_directories(substring_lib PUBLIC
        include/algorithms
        include)

set(TEST_SOURCES
        test/algorithms/test_kmp.cpp
        test/algorithms/test_z_algorithm.cpp
        test/algorithms/test_boyer_moore.cpp
        test/algorithms/test_rabin_karp.cpp
        test/algorithms/test_suffix_array.cpp
        test/algorithms/integration_tests.cpp
        )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address,undefined -g")

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
