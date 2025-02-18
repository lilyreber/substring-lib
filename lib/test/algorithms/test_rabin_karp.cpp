#include <string>
#include <vector>

#include "doctest.h"
#include "substring_lib.h"
#define private public
#include "rabin_karp.h"

// Unit tests for Rabin-Karp algorithm
TEST_CASE("Rabin-Karp unit tests") {
    SUBCASE("Constructor test") {
        // Initialize Rabin-Karp with pattern "example"
        RabinKarp rk("example text");

        // Check if the pattern is stored correctly
        CHECK_EQ(rk.pattern, "example text");
    }

    SUBCASE("Search text") {
        // Initialize Rabin-Karp with pattern "text"
        RabinKarp rk("text");

        // Case 1: Single occurrence
        auto result1 = rk.search("this is a text");
        CHECK_EQ(result1, std::vector<std::size_t>{10});  // "text" starts at index 10

        // Case 2: Multiple occurrences
        auto result2 = rk.search("text some text some text");
        CHECK_EQ(result2, std::vector<std::size_t>{0, 10, 20});  // "text" found at indices 0, 11, and 20

        // Case 3: No match
        auto result3 = rk.search("non match example");
        CHECK(result3.empty());  // "text" is not in the text

        // Case 4: Pattern longer than text
        auto result4 = rk.search("short");
        CHECK(result4.empty());  // Pattern cannot fit in the text

        // Case 5: Matching single character multiple times
        RabinKarp rk_single("a");
        auto result5 = rk_single.search("aaaaaaa");
        CHECK_EQ(result5, std::vector<std::size_t>{0, 1, 2, 3, 4, 5, 6});  // 'a' found at every index

        // Case 6: Long text with pattern at the end
        std::string long_text(10000, 'a');  // Create a long text of 10000 'a's
        long_text += "b";                   // Append 'b' at the end
        RabinKarp rk_long("b");
        auto result6 = rk_long.search(long_text);
        CHECK_EQ(result6, std::vector<std::size_t>{10000});  // 'b' is at the last position
    }
}