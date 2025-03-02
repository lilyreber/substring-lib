#include <algorithm>
#include <string>
#include <vector>

#include "doctest.h"
#include "substring_lib.h"
#define private public
#include "aho_corasick.h"

// unit tests for Aho-Corasick Algorithm

TEST_CASE("Aho-Corasick Algorithm unit tests") {
    SUBCASE("Constructor test") {
        AhoCorasick ahoCorasick("some text for pattern matching");
        CHECK_EQ("some text for pattern matching", ahoCorasick.text);
    }

    SUBCASE("Basic search test") {
        AhoCorasick ahoCorasick("abacabacabac");
        ahoCorasick.buildTrie("ab");
        ahoCorasick.buildFailureLinks();
        CHECK_EQ(ahoCorasick.search("ab"), std::vector<std::size_t>{0, 4, 8});
    }

    SUBCASE("Empty string search test") {
        AhoCorasick ahoCorasick("");
        ahoCorasick.buildTrie("abc");
        ahoCorasick.buildFailureLinks();
        CHECK_EQ(ahoCorasick.search("abc"), std::vector<std::size_t>{});
    }

    SUBCASE("Pattern longer than text test") {
        AhoCorasick ahoCorasick("ab");
        ahoCorasick.buildTrie("abcdef");
        ahoCorasick.buildFailureLinks();
        CHECK_EQ(ahoCorasick.search("abcdef"), std::vector<std::size_t>{});
    }

    SUBCASE("Text contains multiple occurrences of pattern") {
        AhoCorasick ahoCorasick("ababababab");
        ahoCorasick.buildTrie("ab");
        ahoCorasick.buildFailureLinks();
        CHECK_EQ(ahoCorasick.search("ab"), std::vector<std::size_t>{0, 2, 4, 6, 8});
    }
}
