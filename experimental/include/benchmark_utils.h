#ifndef SUBSTRING_LIBRARY_BENCHMARK_UTILS_H
#define SUBSTRING_LIBRARY_BENCHMARK_UTILS_H

#include <random>
#include <string>
#include <unordered_map>

#include "benchmark/benchmark.h"

// Alphabets types
enum class CharsetTypes { LATIN, BINARY };

class RandomStringGenerator {
   private:
    // unordered_map for specify alphabet for type
    std::unordered_map<CharsetTypes, std::string> charsets = {
        {CharsetTypes::LATIN, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"}, {CharsetTypes::BINARY, "01"}};
    std::string randomString = "";

   public:
    // return random string specified size and with chars from alphabet
    std::string getRandomString(std::size_t size, CharsetTypes type) {
        std::string charset = charsets[type];
        randomString.reserve(size);               // reserve memory
        for (std::size_t i = 0; i < size; ++i) {  // fill string with random chars
            randomString += charset[rand() % (charset.size() - 1)];
        }
        return randomString;
    }
};

#endif  // SUBSTRING_LIBRARY_BENCHMARK_UTILS_H
