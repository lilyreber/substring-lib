# The benchmarks are based on the google benchmark framework
include(FetchContent)
FetchContent_Declare(
        google_benchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.8.2
)
set(BENCHMARK_ENABLE_TESTING OFF) # Disable building the tests
FetchContent_MakeAvailable(google_benchmark)


set(BENCHMARK_SOURCES
        benchmark_z_algorithm.cpp
        benchmark_kmp.cpp
        benchmark_boyer_moore.cpp
        benchmark_rabin_karp.cpp
        benchmark_suffix_array.cpp)

foreach (BENCHMARK_SOURCE ${BENCHMARK_SOURCES})
    add_executable(env_${BENCHMARK_SOURCE}
            benchmark.cpp
            algorithms/${BENCHMARK_SOURCE})
    target_link_libraries(env_${BENCHMARK_SOURCE} PRIVATE
            substring_lib
            benchmark
            )
    target_include_directories(env_${BENCHMARK_SOURCE} PRIVATE ${CMAKE_SOURCE_DIR}/lib/include)
endforeach ()
