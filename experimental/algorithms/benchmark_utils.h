#ifndef SUBSTRING_LIBRARY_BENCHMARK_UTILS_H
#define SUBSTRING_LIBRARY_BENCHMARK_UTILS_H

#include <benchmark/benchmark.h>

#include <random>
#include <string>
#include <unordered_map>

enum class CHARSETS_TYPES { LATIN, BINARY };

static std::unordered_map<CHARSETS_TYPES, std::string> charsets = {
    {CHARSETS_TYPES::LATIN, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"}, {CHARSETS_TYPES::BINARY, "01"}};

std::string generate_random_string(std::size_t size, CHARSETS_TYPES type) {
    std::string charset = charsets[type];
    static std::string result;
    result.reserve(size);
    for (std::size_t i = 0; i < size; ++i) {
        result += charset[rand() % (charset.size() - 1)];
    }
    return result;
}

#endif  // SUBSTRING_LIBRARY_BENCHMARK_UTILS_H
