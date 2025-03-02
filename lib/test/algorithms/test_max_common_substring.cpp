#include <algorithm>
#include <string>
#include <vector>

#include "doctest.h"
#include "substring_lib.h"
#define private public
#include "max_common_substring.h"

// unit tests for Max Common Substring Algorithm

TEST_CASE("Max Common Substring Algorithm unit tests") {
    SUBCASE("Constructor test") {
        MaxCommonSubstring maxCommonSubstring("some text for pattern matching");
        CHECK_EQ("some text for pattern matching", maxCommonSubstring.text);
    }

    SUBCASE("Basic search test") {
        MaxCommonSubstring maxCommonSubstring("abacabacabac");
        CHECK_EQ(maxCommonSubstring.search("ab"), std::vector<std::size_t>{0, 4, 8});
    }

    SUBCASE("Pattern longer than text test") {
        MaxCommonSubstring maxCommonSubstring("ab");
        CHECK_EQ(maxCommonSubstring.search("abcdef"), std::vector<std::size_t>{});
    }

    SUBCASE("Multiple occurrences of the pattern test") {
        MaxCommonSubstring maxCommonSubstring("ababababab");
        CHECK_EQ(maxCommonSubstring.search("ab"), std::vector<std::size_t>{0, 2, 4, 6, 8});
    }

    SUBCASE("Empty string search test") {
        MaxCommonSubstring maxCommonSubstring("");
        CHECK_EQ(maxCommonSubstring.search("abc"), std::vector<std::size_t>{});
    }

    SUBCASE("Empty pattern test") {
        MaxCommonSubstring maxCommonSubstring("some text");
        CHECK_EQ(maxCommonSubstring.search(""), std::vector<std::size_t>{});
    }

    SUBCASE("No match test") {
        MaxCommonSubstring maxCommonSubstring("hello world");
        CHECK_EQ(maxCommonSubstring.search("goodbye"), std::vector<std::size_t>{});
    }
}
