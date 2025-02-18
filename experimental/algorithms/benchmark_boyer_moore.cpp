#include <benchmark/benchmark.h>

#include <random>
#include <string>

#include "benchmark_utils.h"
#include "substring_lib.h"

// Benchmark: search pattern in small text (cold)
static void BM_Boyer_Moore_Cold(benchmark::State &state) {
    std::string text = "hello world, this is a test string";
    std::string pattern = "test";
    for (auto _ : state) {
        benchmark::DoNotOptimize(search_pattern(text, pattern, AlgorithmType::BOYER_MOORE));
    }
}

BENCHMARK(BM_Boyer_Moore_Cold);

// Benchmark: search pattern in large text (100MB, cold)
static void BM_Boyer_Moore_LargeText_Cold(benchmark::State &state) {
    std::string text = generate_random_string(100 * 1024 * 1024, CHARSETS_TYPES::LATIN);  // 100MB
    std::string pattern = "abcdef";
    for (auto _ : state) {
        benchmark::DoNotOptimize(search_pattern(text, pattern, AlgorithmType::BOYER_MOORE));
    }
}

BENCHMARK(BM_Boyer_Moore_LargeText_Cold);

// Benchmark: search pattern in large text (100MB, hot)
static void BM_Boyer_Moore_Hot(benchmark::State &state) {
    std::string text = generate_random_string(10 * 1024 * 1024, CHARSETS_TYPES::LATIN);  // 10MB
    std::string pattern = "xyz";

    for (auto _ : state) {
        benchmark::DoNotOptimize(search_pattern(text, pattern, AlgorithmType::BOYER_MOORE));
    }
}

BENCHMARK(BM_Boyer_Moore_Hot);

// Benchmark: speed per mb
static void BM_Boyer_Moore_Per_MB(benchmark::State &state) {
    std::size_t data_size = state.range(0);
    std::string text = generate_random_string(data_size, CHARSETS_TYPES::LATIN);
    std::string pattern = "pattern";
    for (auto _ : state) {
        benchmark::DoNotOptimize(search_pattern(text, pattern, AlgorithmType::BOYER_MOORE));
        state.SetBytesProcessed(data_size);
    }
}

BENCHMARK(BM_Boyer_Moore_Per_MB)->Range(1024 * 1024, 100 * 1024 * 1024);
//
// BENCHMARK(BM_Boyer_Moore_Cold_Bin_Str);
// BENCHMARK(BM_Boyer_Moore_LargeText_Cold_Bin_Str);
// BENCHMARK(BM_Boyer_Moore_Hot_Bin_Str);
// BENCHMARK(BM_Boyer_Moore_Per_MB_Bin_Str)->Range(1024 * 1024, 100 * 1024 * 1024);