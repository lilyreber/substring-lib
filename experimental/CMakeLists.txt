# The benchmarks are based on the google benchmark framework
include(FetchContent)
FetchContent_Declare(
        google_benchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.8.2
)
set(BENCHMARK_ENABLE_TESTING OFF) # Disable building the tests
FetchContent_MakeAvailable(google_benchmark)

FetchContent_Declare(
        json
        URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(json)

include_directories(include)

add_executable(env_benchmark
        benchmark.cpp
        )
target_link_libraries(env_benchmark PRIVATE
        substring_lib
        benchmark
        nlohmann_json
        )

target_include_directories(env_benchmark PRIVATE ${CMAKE_SOURCE_DIR}/lib/include)

target_compile_definitions(env_benchmark PRIVATE PROJECT_ROOT="${CMAKE_CURRENT_SOURCE_DIR}")
