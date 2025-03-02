#include <algorithm>
#include <string>
#include <vector>

#include "doctest.h"
#include "substring_lib.h"
#define private public
#include "aho_corasick.h"

// Unit tests for Aho-Corasick Algorithm

TEST_CASE("Aho-Corasick Algorithm unit tests") {

    SUBCASE("Basic search test") {
        AhoCorasick ahoCorasick("ab");
        ahoCorasick.buildTrie("ab");
        ahoCorasick.buildFailureLinks();
        CHECK_EQ(ahoCorasick.search("abacabacabac"), std::vector<std::size_t>{0, 4, 8});
    }

    SUBCASE("Empty string search test") {
        AhoCorasick ahoCorasick("abc");
        ahoCorasick.buildTrie("abc");
        ahoCorasick.buildFailureLinks();
        CHECK_EQ(ahoCorasick.search(""), std::vector<std::size_t>{});
    }

    SUBCASE("Pattern longer than text test") {
        AhoCorasick ahoCorasick("abcdef");
        ahoCorasick.buildTrie("abcdef");
        ahoCorasick.buildFailureLinks();
        CHECK_EQ(ahoCorasick.search("ab"), std::vector<std::size_t>{});
    }

    SUBCASE("Text contains multiple occurrences of pattern") {
        AhoCorasick ahoCorasick("ab");
        ahoCorasick.buildTrie("ab");
        ahoCorasick.buildFailureLinks();
        CHECK_EQ(ahoCorasick.search("ababababab"), std::vector<std::size_t>{0, 2, 4, 6, 8});
    }

    SUBCASE("Single character pattern search test") {
        AhoCorasick ahoCorasick("a");
        ahoCorasick.buildTrie("a");
        ahoCorasick.buildFailureLinks();
        CHECK_EQ(ahoCorasick.search("aaaaaaaaaa"), std::vector<std::size_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    }

    SUBCASE("Pattern not found in text test") {
        AhoCorasick ahoCorasick("xyz");
        ahoCorasick.buildTrie("xyz");
        ahoCorasick.buildFailureLinks();
        CHECK_EQ(ahoCorasick.search("abcdef"), std::vector<std::size_t>{});
    }

    SUBCASE("Pattern at the end of text test") {
        AhoCorasick ahoCorasick("abc");
        ahoCorasick.buildTrie("abc");
        ahoCorasick.buildFailureLinks();
        CHECK_EQ(ahoCorasick.search("xyzabc"), std::vector<std::size_t>{3});
    }

    SUBCASE("Pattern at the beginning of text test") {
        AhoCorasick ahoCorasick("abc");
        ahoCorasick.buildTrie("abc");
        ahoCorasick.buildFailureLinks();
        CHECK_EQ(ahoCorasick.search("abcxyz"), std::vector<std::size_t>{0});
    }

    SUBCASE("Overlapping patterns test") {
        AhoCorasick ahoCorasick("aba");
        ahoCorasick.buildTrie("aba");
        ahoCorasick.buildFailureLinks();
        CHECK_EQ(ahoCorasick.search("ababababa"), std::vector<std::size_t>{0, 2, 4, 6});
    }

    SUBCASE("Multiple patterns test") {
        AhoCorasick ahoCorasick("ab");
        ahoCorasick.buildTrie("ab");
        ahoCorasick.buildFailureLinks();
        CHECK_EQ(ahoCorasick.search("abacababac"), std::vector<std::size_t>{0, 4, 6});
    }
}