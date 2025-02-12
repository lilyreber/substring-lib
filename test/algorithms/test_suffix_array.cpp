#include <string>
#include <vector>

#include "doctest.h"
#include "substring_lib.h"

TEST_CASE("Empty text and empty pattern (Suffix Array)") {
    auto result = search_pattern("", "", AlgorithmType::SUFFIX_ARRAY);
    CHECK(result.empty());
}

TEST_CASE("Empty text and not empty pattern (Suffix Array)") {
    auto result = search_pattern("", "pattern", AlgorithmType::SUFFIX_ARRAY);
    CHECK(result.empty());
}

TEST_CASE("Not empty text and empty pattern (Suffix Array)") {
    auto result = search_pattern("aaaaaaaaaaaaaaaaaaaaa", "", AlgorithmType::SUFFIX_ARRAY);
    CHECK(result.empty());
}

TEST_CASE("Simple text and simple pattern (Suffix Array)") {
    auto result = search_pattern("simple text", "simple", AlgorithmType::SUFFIX_ARRAY);
    CHECK_EQ(result, std::vector<std::size_t>{0});
}

TEST_CASE("Text and pattern are the same (Suffix Array)") {
    auto result = search_pattern("simple text", "simple text", AlgorithmType::SUFFIX_ARRAY);
    CHECK_EQ(result, std::vector<std::size_t>{0});
}

TEST_CASE("Text with one letter and one letter pattern (Suffix Array)") {
    auto result = search_pattern("aaaaaaaaaaaaaaaaaaaaa", "a", AlgorithmType::SUFFIX_ARRAY);
    CHECK_EQ(result,
             std::vector<std::size_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20});
}

TEST_CASE("Text and big pattern (Suffix Array)") {
    auto result = search_pattern("some text", "some bigger text", AlgorithmType::SUFFIX_ARRAY);
    CHECK(result.empty());
}

TEST_CASE("Text with some patterns (Suffix Array)") {
    auto result = search_pattern("some text some text", "some text", AlgorithmType::SUFFIX_ARRAY);
    CHECK_EQ(result, std::vector<std::size_t>{0, 10});
}

TEST_CASE("Text with some patterns (hard) (Suffix Array)") {
    auto result = search_pattern("acbccababcabcaacab", "cab", AlgorithmType::SUFFIX_ARRAY);
    CHECK_EQ(result, std::vector<std::size_t>{4, 9, 15});
}

TEST_CASE("Long text and long pattern (Suffix Array)") {
    auto result = search_pattern(std::string(10000, 'a') + 'b', std::string(10000, 'a'), AlgorithmType::SUFFIX_ARRAY);
    CHECK_EQ(result, std::vector<std::size_t>{0});
}

TEST_CASE("Long text and short pattern (Suffix Array)") {
    std::string text;
    for (int i = 0; i < 5000; ++i) {
        text += "ab";
    }
    auto result = search_pattern(text, "ab", AlgorithmType::SUFFIX_ARRAY);
    std::vector<std::size_t> expected;
    for (std::size_t i = 0; i < text.size(); i += 2) {
        expected.push_back(i);
    }
    CHECK_EQ(result, expected);
}
