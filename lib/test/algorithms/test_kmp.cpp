#include <string>
#include <vector>

#include "doctest.h"
#include "substring_lib.h"

#define private public
#include "kmp.h"

// unit tests for kmp
TEST_CASE("KMP unit tests") {
    SUBCASE("Constructor easy test") {
        std::string expected = "example";
        auto kmp = KMP(expected);
        CHECK_EQ(expected, kmp.pattern);
    }

    SUBCASE("Constructor long test") {
        std::string expected = std::string(1000, 'a') + std::string(1000, 'b');
        auto kmp = KMP(expected);
        CHECK_EQ(expected, kmp.pattern);
    }

    SUBCASE("Compute Longest Prefix SuffixArray single char test") {
        //        a
        //        ^a
        KMP kmp("a");
        std::vector<std::size_t> expected = {0};
        CHECK_EQ(expected, kmp.lps);
    }

    SUBCASE("Compute Longest Prefix SuffixArray empty test") {
        KMP kmp("");
        CHECK_FALSE(!kmp.lps.empty());
    }

    SUBCASE("Compute Longest Prefix SuffixArray easy test") {
        //        aba  b
        //          ^a ^ab
        KMP kmp("abab");
        std::vector<std::size_t> expected = {0, 0, 1, 2};
        CHECK_EQ(expected, kmp.lps);
    }

    SUBCASE("Constructor repeat test") {
        //        aa  a   a
        //         ^a ^aa ^aaa
        KMP kmp("aaaa");
        std::vector<std::size_t> expected = {0, 1, 2, 3};
        CHECK_EQ(expected, kmp.lps);
    }

    SUBCASE("Constructor repeat not so easy test") {
        //        aa  ba  a   b    a     a      a
        //         ^a  ^a ^aa ^aab ^aaba ^aabaa ^aa
        KMP kmp("aabaabaaa");
        std::vector<std::size_t> expected = {0, 1, 0, 1, 2, 3, 4, 5, 2};
        CHECK_EQ(expected, kmp.lps);
    }

    SUBCASE("Compute Longest Prefix SuffixArray long test") {
        KMP kmp(std::string(1000, 'a'));
        std::vector<std::size_t> expected(1000, 0);
        for (int i = 0; i < expected.size(); ++i) {
            expected[i] = i;
        }
        CHECK_EQ(expected, kmp.lps);
    }
}
