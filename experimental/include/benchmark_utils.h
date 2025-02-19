#ifndef SUBSTRING_LIBRARY_BENCHMARK_UTILS_H
#define SUBSTRING_LIBRARY_BENCHMARK_UTILS_H

#include <random>
#include <string>
#include <unordered_map>

#include "benchmark/benchmark.h"

enum class CharsetTypes { LATIN, BINARY };

class RandomStringGenerator {
   private:
    std::unordered_map<CharsetTypes, std::string> charsets = {
        {CharsetTypes::LATIN, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"}, {CharsetTypes::BINARY, "01"}};
    std::string randomString = "";

   public:
    std::string getRandomString(std::size_t size, CharsetTypes type) {
        std::string charset = charsets[type];
        randomString.reserve(size);
        for (std::size_t i = 0; i < size; ++i) {
            randomString += charset[rand() % (charset.size() - 1)];
        }
        return randomString;
    }
};

#endif  // SUBSTRING_LIBRARY_BENCHMARK_UTILS_H
