cmake_minimum_required(VERSION 3.23)
project(experimental)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-fsanitize=address,undefined)
add_link_options(-fsanitize=address,undefined)

add_executable(experimental_env benchmark.cpp)

# Connect library
target_link_libraries(experimental_env PRIVATE substring_lib)
target_include_directories(experimental_env PRIVATE ${CMAKE_SOURCE_DIR}/lib/include)