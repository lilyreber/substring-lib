#include <algorithm>
#include <string>
#include <vector>

#include "doctest.h"
#include "substring_lib.h"
#define private public
#include "not_so_naive.h"

// unit tests for Not So Naive Algorithm

TEST_CASE("Not So Naive Algorithm unit tests") {
    SUBCASE("Constructor test") {
        NotSoNaive notSoNaive("pattern");
        CHECK_EQ("pattern", notSoNaive.text);
    }

    SUBCASE("Naive search test") {
        NotSoNaive notSoNaive("aaaabbbaaaa");
        CHECK_EQ(std::vector<std::size_t>{0, 1, 2, 3, 7, 8, 9, 10}, notSoNaive.naiveSearch("a"));
        CHECK_EQ(std::vector<std::size_t>{}, notSoNaive.naiveSearch("c"));
    }

    SUBCASE("Search search test") {
        NotSoNaive notSoNaive("some text text some");
        CHECK_EQ(std::vector<std::size_t>{0, 15}, notSoNaive.naiveSearch("some"));
        CHECK_EQ(std::vector<std::size_t>{}, notSoNaive.naiveSearch(""));
        CHECK_EQ(std::vector<std::size_t>{}, notSoNaive.naiveSearch("a"));
    }

    SUBCASE("Empty text search test") {
        auto notSoNaive = NotSoNaive("");
        CHECK_EQ(std::vector<std::size_t>{}, notSoNaive.naiveSearch(""));
        CHECK_EQ(std::vector<std::size_t>{}, notSoNaive.naiveSearch("some text"));
    }

    SUBCASE("Long text search test") {
        NotSoNaive notSoNaive(std::string(10000, 'a') + 'b');

        CHECK(notSoNaive.search("some text").empty());

        std::vector<std::size_t> expected;
        for (std::size_t i = 0; i < 10000; ++i) {
            expected.push_back(i);
        }
        CHECK(notSoNaive.search("").empty());
        CHECK_EQ(notSoNaive.search("a"), expected);
        CHECK_EQ(notSoNaive.search("b"), std::vector<std::size_t>{10000});
    }
}
