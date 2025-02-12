cmake_minimum_required(VERSION 3.23)
project(substring_library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-fsanitize=address,undefined)
add_link_options(-fsanitize=address,undefined)

add_subdirectory(lib)
add_subdirectory(experimental)

enable_testing()