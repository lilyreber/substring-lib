#include <algorithm>
#include <string>
#include <vector>

#include "doctest.h"
#include "substring_lib.h"
#define private public
#include "suffix_array.h"

// unit tests for Suffix Array Algorithm

TEST_CASE("Suffix Array unit tests") {
    SUBCASE("Constructor test") {
        // anana ana a banana nana na
        //   1    3  5    0    2   4

        auto suffixArray = SuffixArray("banana");
        auto expected = std::vector<std::size_t>{1, 3, 5, 0, 2, 4};
        CHECK_EQ(expected, suffixArray.suffixArray);
    }

    SUBCASE("LowerBound test") {
        SuffixArray suffixArray("banana");

        CHECK_EQ(0, suffixArray.lowerBound("ana"));
        CHECK_EQ(3, suffixArray.lowerBound("banana"));
        CHECK_EQ(3, suffixArray.lowerBound("apple"));
    }

    SUBCASE("UpperBound test") {
        SuffixArray suffixArray("banana");

        CHECK_EQ(3, suffixArray.upperBound("ana"));
        CHECK_EQ(4, suffixArray.upperBound("banana"));
        CHECK_EQ(3, suffixArray.upperBound("apple"));
    }

    SUBCASE("Constructor test empty") {
        auto suffixArray = SuffixArray("");
        CHECK(suffixArray.suffixArray.empty());
    }

    SUBCASE("LowerBound test empty") {
        SuffixArray suffixArray("");

        CHECK_EQ(0, suffixArray.lowerBound("ana"));
        CHECK_EQ(0, suffixArray.lowerBound("banana"));
        CHECK_EQ(0, suffixArray.lowerBound("apple"));
    }

    SUBCASE("UpperBound test empty") {
        SuffixArray suffixArray("");

        CHECK_EQ(0, suffixArray.upperBound("ana"));
        CHECK_EQ(0, suffixArray.upperBound("banana"));
        CHECK_EQ(0, suffixArray.upperBound("apple"));
    }

    SUBCASE("Search test") {
        SuffixArray suffixArray("banana");

        CHECK_EQ(suffixArray.search("a"), std::vector<std::size_t>{1, 3, 5});
        CHECK(suffixArray.search("").empty());
    }

    SUBCASE("Empty text search test") {
        SuffixArray suffixArray("");

        CHECK(suffixArray.search("some text").empty());
        CHECK(suffixArray.search("").empty());
    }

    SUBCASE("Long text search test") {
        SuffixArray suffixArray(std::string(10000, 'a') + 'b');

        CHECK(suffixArray.search("some text").empty());

        std::vector<std::size_t> expected;
        for (std::size_t i = 0; i < 10000; ++i) {
            expected.push_back(i);
        }
        CHECK(suffixArray.search("").empty());
        CHECK_EQ(suffixArray.search("a"), expected);
        CHECK_EQ(suffixArray.search("b"), std::vector<std::size_t>{10000});
    }
}
