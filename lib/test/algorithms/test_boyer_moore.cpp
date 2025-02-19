#include <string>
#include <vector>

#include "doctest.h"

#define private public

#include "boyer_moore.h"

// unit tests for Boyer-Moore algorithm
TEST_CASE("Boyer-Moore unit tests") {
    SUBCASE("Constructor easy test") {
        // Initialize Rabin-Karp with pattern "example"
        std::string expected = "example";
        auto bm = BoyerMoore(expected);
        CHECK_EQ(expected, bm.pattern);
    }

    SUBCASE("Constructor long test") {
        // Initialize Rabin-Karp with long pattern
        std::string expected = std::string(1000, 'a') + std::string(1000, 'b');
        auto bm = BoyerMoore(expected);
        CHECK_EQ(expected, bm.pattern);
    }

    SUBCASE("Search text") {
        // Initialize Rabin-Karp with pattern "text"
        BoyerMoore bm("text");

        // Case 1: Single occurrence
        auto result1 = bm.search("this is a text");
        CHECK_EQ(result1, std::vector<std::size_t>{10});  // "text" starts at index 10

        // Case 2: Multiple occurrences
        auto result2 = bm.search("text some text some text");
        CHECK_EQ(result2, std::vector<std::size_t>{0, 10, 20});  // "text" found at indices 0, 11, and 20

        // Case 3: No match
        auto result3 = bm.search("non match example");
        CHECK(result3.empty());  // "text" is not in the text

        // Case 4: Pattern longer than text
        auto result4 = bm.search("short");
        CHECK(result4.empty());  // Pattern cannot fit in the text

        // Case 5: Matching single character multiple times
        BoyerMoore bm_single("a");
        auto result5 = bm_single.search("aaaaaaa");
        CHECK_EQ(result5, std::vector<std::size_t>{0, 1, 2, 3, 4, 5, 6});  // 'a' found at every index

        // Case 6: Long text with pattern at the end
        std::string long_text(10000, 'a');  // Create a long text of 10000 'a's
        long_text += "b";                   // Append 'b' at the end
        BoyerMoore bm_long("b");
        auto result6 = bm_long.search(long_text);
        CHECK_EQ(result6, std::vector<std::size_t>{10000});  // 'b' is at the last position
    }
}
