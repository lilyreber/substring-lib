#include <string>
#include <vector>

#include "doctest.h"
#include "substring_lib.h"

// tests for search function of any algorithm
void run_tests_for_algorithm(AlgorithmType algorithm);

TEST_CASE("Test search_pattern for all algorithms") {
    SUBCASE("Knuth-Morris-Pratt algorithm") { run_tests_for_algorithm(AlgorithmType::KMP); }
    SUBCASE("Boyer-Moore algorithm") { run_tests_for_algorithm(AlgorithmType::BOYER_MOORE); }
    SUBCASE("Rabin-Karp algorithm") { run_tests_for_algorithm(AlgorithmType::RABIN_KARP); }
    SUBCASE("Suffix Array algorithm") { run_tests_for_algorithm(AlgorithmType::SUFFIX_ARRAY); }
    SUBCASE("Z algorithm") { run_tests_for_algorithm(AlgorithmType::Z_ALGORITHM); }
    SUBCASE("Not So Naive algorithm") { run_tests_for_algorithm(AlgorithmType::NOT_SO_NAIVE); }
    SUBCASE("Aho-Corasick algorithm") { run_tests_for_algorithm(AlgorithmType::AHO_CORASICK); }
    SUBCASE("Max Common Substring algorithm") { run_tests_for_algorithm(AlgorithmType::MAX_COMMON_SUBSTRING);}
}

void run_tests_for_algorithm(AlgorithmType algorithm) {
    SUBCASE("Empty text and empty pattern") {
        auto result = search_pattern("", "", algorithm);
        CHECK(result.empty());
    }

    SUBCASE("Empty text and not empty pattern") {
        auto result = search_pattern("", "pattern", algorithm);
        CHECK(result.empty());
    }

    SUBCASE("Not empty text and empty pattern") {
        auto result = search_pattern("aaaaaaaaaaaaaaaaaaaaa", "", algorithm);
        CHECK(result.empty());
    }

    SUBCASE("Simple text and simple pattern") {
        auto result = search_pattern("simple text", "simple", algorithm);
        CHECK_EQ(result, std::vector<std::size_t>{0});
    }

    SUBCASE("Text and pattern are the same") {
        auto result = search_pattern("simple text", "simple text", algorithm);
        CHECK_EQ(result, std::vector<std::size_t>{0});
    }

    SUBCASE("Text with one letter and one letter pattern") {
        auto result = search_pattern("aaaaaaaaaaaaaaaaaaaaa", "a", algorithm);
        CHECK_EQ(result,
                 std::vector<std::size_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20});
    }

    SUBCASE("Text and big pattern") {
        auto result = search_pattern("some text", "some bigger text", algorithm);
        CHECK(result.empty());
    }

    SUBCASE("Text with some patterns") {
        auto result = search_pattern("some text some text some", "some text", algorithm);
        CHECK_EQ(result, std::vector<std::size_t>{0, 10});
    }

    SUBCASE("Text with some patterns (hard)") {
        auto result = search_pattern("acbccababcabcaacab", "cab", algorithm);
        CHECK_EQ(result, std::vector<std::size_t>{4, 9, 15});
    }

    SUBCASE("Long text and long pattern") {
        auto result = search_pattern(std::string(10000, 'a') + 'b', std::string(10000, 'a'), algorithm);
        CHECK_EQ(result, std::vector<std::size_t>{0});
    }

    SUBCASE("Long text and short pattern") {
        std::string text;
        for (int i = 0; i < 5000; ++i) {
            text += "ab";
        }
        auto result = search_pattern(text, "ab", algorithm);
        std::vector<std::size_t> expected;
        for (std::size_t i = 0; i < text.size(); i += 2) {
            expected.push_back(i);
        }
        CHECK_EQ(result, expected);
    }
}
