#include "doctest.h"
#include "substring_lib.h"
#include "kmp.h"
#include <vector>
#include <string>
#include <iostream>

TEST_CASE("Empty text and empty pattern") {
    std::vector<int> result = search_pattern("", "", AlgorithmType::KMP);
    CHECK(result.empty());
}

TEST_CASE("Empty text and not empty pattern") {
    std::vector<int> result = search_pattern("", "pattern", AlgorithmType::KMP);
    CHECK(result.empty());
}

TEST_CASE("Not empty text and empty pattern") {
    std::vector<int> result = search_pattern("aaaaaaaaaaaaaaaaaaaaa", "", AlgorithmType::KMP);
    CHECK(result.empty());
}

TEST_CASE("Simple text and simple pattern") {
    std::vector<int> result = search_pattern("simple text", "simple", AlgorithmType::KMP);
    CHECK_EQ(result, std::vector{0});
}

TEST_CASE("Text and pattern are the same") {
    std::vector<int> result = search_pattern("simple text", "simple text", AlgorithmType::KMP);
    CHECK_EQ(result, std::vector{0});
}

TEST_CASE("Text with one letter and one letter pattern") {
    std::vector<int> result = search_pattern("aaaaaaaaaaaaaaaaaaaaa", "a", AlgorithmType::KMP);
    CHECK_EQ(result, std::vector{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20});
}

TEST_CASE("Text and big pattern") {
    std::vector<int> result = search_pattern("some text", "some bigger text", AlgorithmType::KMP);
    CHECK(result.empty());
}

TEST_CASE("Text with some patterns") {
    std::vector<int> result = search_pattern("some text some text some", "some text", AlgorithmType::KMP);
    CHECK_EQ(result, std::vector{0, 10});
}

TEST_CASE("Text with some patterns (hard)") {
    std::vector<int> result = search_pattern("acbccababcabcaacab", "cab", AlgorithmType::KMP);
    CHECK_EQ(result, std::vector{4, 9, 15});
}

TEST_CASE("Long text and long pattern") {
    std::vector<int> result = search_pattern(std::string(10000, 'a') + 'b', std::string(10000, 'a'), AlgorithmType::KMP);
    CHECK_EQ(result, std::vector{0});
}

TEST_CASE("Long text and short pattern") {
    std::string text;
    for (int i = 0; i < 5000; ++i) {
        text += "ab";
    }
    std::vector<int> result = search_pattern(text, "ab", AlgorithmType::KMP);
    std::vector<int> expected;
    for (int i = 0; i < 10000; i += 2) {
        expected.push_back(i);
    }
    CHECK_EQ(result, expected);
}
