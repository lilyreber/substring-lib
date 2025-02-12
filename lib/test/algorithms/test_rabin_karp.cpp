#include <string>
#include <vector>

#include "doctest.h"
#include "substring_lib.h"

TEST_CASE("Empty text and empty pattern (Rabin-Karp)") {
    auto result = search_pattern("", "", AlgorithmType::RABIN_KARP);
    CHECK(result.empty());
}

TEST_CASE("Empty text and not empty pattern (Rabin-Karp)") {
    auto result = search_pattern("", "pattern", AlgorithmType::RABIN_KARP);
    CHECK(result.empty());
}

TEST_CASE("Not empty text and empty pattern (Rabin-Karp)") {
    auto result = search_pattern("aaaaaaaaaaaaaaaaaaaaa", "", AlgorithmType::RABIN_KARP);
    CHECK(result.empty());
}

TEST_CASE("Simple text and simple pattern (Rabin-Karp)") {
    auto result = search_pattern("simple text", "simple", AlgorithmType::RABIN_KARP);
    CHECK_EQ(result, std::vector<std::size_t>{0});
}

TEST_CASE("Text and pattern are the same (Rabin-Karp)") {
    auto result = search_pattern("simple text", "simple text", AlgorithmType::RABIN_KARP);
    CHECK_EQ(result, std::vector<std::size_t>{0});
}

TEST_CASE("Text with one letter and one letter pattern (Rabin-Karp)") {
    auto result = search_pattern("aaaaaaaaaaaaaaaaaaaaa", "a", AlgorithmType::RABIN_KARP);
    CHECK_EQ(result,
             std::vector<std::size_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20});
}

TEST_CASE("Text and big pattern (Rabin-Karp)") {
    auto result = search_pattern("some text", "some bigger text", AlgorithmType::RABIN_KARP);
    CHECK(result.empty());
}

TEST_CASE("Text with some patterns (Rabin-Karp)") {
    auto result = search_pattern("some text some text some", "some text", AlgorithmType::RABIN_KARP);
    CHECK_EQ(result, std::vector<std::size_t>{0, 10});
}

TEST_CASE("Text with some patterns (hard) (Rabin-Karp)") {
    auto result = search_pattern("acbccababcabcaacab", "cab", AlgorithmType::RABIN_KARP);
    CHECK_EQ(result, std::vector<std::size_t>{4, 9, 15});
}

TEST_CASE("Long text and long pattern (Rabin-Karp)") {
    auto result = search_pattern(std::string(10000, 'a') + 'b', std::string(10000, 'a'), AlgorithmType::RABIN_KARP);
    CHECK_EQ(result, std::vector<std::size_t>{0});
}

TEST_CASE("Long text and short pattern (Rabin-Karp)") {
    std::string text;
    for (int i = 0; i < 5000; ++i) {
        text += "ab";
    }
    auto result = search_pattern(text, "ab", AlgorithmType::RABIN_KARP);
    auto expected = std::vector<std::size_t>();
    for (std::size_t i = 0; i < text.size(); i += 2) {
        expected.push_back(i);
    }
    CHECK_EQ(result, expected);
}
