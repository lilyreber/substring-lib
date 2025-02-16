#include "kmp.h"

// Constructor to initialize the KMP object with the given pattern
KMP::KMP(const std::string &pattern) : pattern(pattern) {
    computeLongestPrefixSuffixArray();  // Precompute the longest prefix suffix (LPS) array
}

// Function to compute the LPS (Longest Prefix Suffix) array
void KMP::computeLongestPrefixSuffixArray() {
    auto m = pattern.size();  // Length of the pattern
    longestPrefixSuffix.resize(m, 0);
    std::size_t j = 0;  // Length of the previous longest prefix suffix

    for (std::size_t i = 1; i < m; ++i) {
        // Adjust the length of the prefix suffix if there's a mismatch
        while (j > 0 && pattern[i] != pattern[j]) {
            j = longestPrefixSuffix[j - 1];
        }
        // If characters match, extend the prefix length
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        longestPrefixSuffix[i] = j;  // Store the current length of the prefix suffix
    }
}

// Search function to find all occurrences of the pattern in the given text
std::vector<std::size_t> KMP::search(const std::string &text) const {
    std::vector<std::size_t> result;  // Stores the starting indices of matches
    auto n = text.size();             // Length of the text
    auto m = pattern.size();          // Length of the pattern
    std::size_t j = 0;                // Index for the pattern

    // If the pattern is empty, return an empty result
    if (m == 0) {
        return result;
    }

    // Traverse the text to find pattern matches
    for (std::size_t i = 0; i < n; ++i) {
        // Adjust the pattern index on mismatch
        while (j > 0 && text[i] != pattern[j]) {
            j = longestPrefixSuffix[j - 1];
        }
        // If characters match, move to the next character in the pattern
        if (text[i] == pattern[j]) {
            ++j;
        }
        // If the entire pattern is matched
        if (j == m) {
            result.push_back(i - m + 1);     // Store the starting index of the match
            j = longestPrefixSuffix[j - 1];  // Continue searching for the next match
        }
    }

    return result;  // Return all found occurrences
}
