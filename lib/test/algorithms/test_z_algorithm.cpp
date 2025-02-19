#include <string>
#include <vector>

#include "doctest.h"
#define private public
#include "z_algorithm.h"

// Unit tests for Z-algorithm
TEST_CASE("Z-function tests") {
    // Initialize Z-algorithm with pattern "example"
    SUBCASE("Constructor easy test") {
        std::string expected = "example";
        auto z = ZAlgorithm(expected);
        CHECK_EQ(expected, z.pattern);
    }

    // Initialize Z-algorithm with long pattern
    SUBCASE("Constructor long test") {
        std::string expected = std::string(1000, 'a') + std::string(1000, 'b');
        auto z = ZAlgorithm(expected);
        CHECK_EQ(expected, z.pattern);
    }

    // empty string z-function test
    SUBCASE("Empty string") {
        ZAlgorithm zAlgorithm("pattern");
        std::string s = "";
        std::vector<std::size_t> result = zAlgorithm.computeZFunction(s);
        CHECK(result.empty());
    }

    // Single character string test
    SUBCASE("Single character") {
        ZAlgorithm zAlgorithm("pattern");
        std::string s = "a";
        std::vector<std::size_t> result = zAlgorithm.computeZFunction(s);
        REQUIRE_EQ(result.size(), 1);
        CHECK_EQ(result[0], 0);
    }

    // Test for a string with repeated characters
    SUBCASE("Repeated characters") {
        ZAlgorithm zAlgorithm("pattern");
        std::string s = "aaaa";
        std::vector<std::size_t> result = zAlgorithm.computeZFunction(s);
        std::vector<std::size_t> expected = {0, 3, 2, 1};
        REQUIRE_EQ(result.size(), expected.size());
        for (std::size_t i = 0; i < result.size(); ++i) {
            CHECK_EQ(result[i], expected[i]);
        }
    }

    // Test for a string with unique characters
    SUBCASE("Unique characters") {
        ZAlgorithm zAlgorithm("pattern");
        std::string s = "abcdef";
        std::vector<std::size_t> result = zAlgorithm.computeZFunction(s);
        std::vector<std::size_t> expected = {0, 0, 0, 0, 0, 0};
        REQUIRE_EQ(result.size(), expected.size());
        for (std::size_t i = 0; i < result.size(); ++i) {
            CHECK_EQ(result[i], expected[i]);
        }
    }

    // Test for a string with partially repeated characters
    SUBCASE("Partially repeated characters") {
        ZAlgorithm zAlgorithm("pattern");
        std::string s = "aabcaab";
        std::vector<std::size_t> result = zAlgorithm.computeZFunction(s);
        std::vector<std::size_t> expected = {0, 1, 0, 0, 3, 1, 0};
        REQUIRE_EQ(result.size(), expected.size());
        for (std::size_t i = 0; i < result.size(); ++i) {
            CHECK_EQ(result[i], expected[i]);
        }
    }

    // Test for a string with a repeating pattern
    SUBCASE("Repeated pattern") {
        ZAlgorithm zAlgorithm("pattern");
        std::string s = "abababab";
        std::vector<std::size_t> result = zAlgorithm.computeZFunction(s);
        std::vector<std::size_t> expected = {0, 0, 6, 0, 4, 0, 2, 0};
        REQUIRE_EQ(result.size(), expected.size());
        for (std::size_t i = 0; i < result.size(); ++i) {
            CHECK_EQ(result[i], expected[i]);
        }
    }
}
