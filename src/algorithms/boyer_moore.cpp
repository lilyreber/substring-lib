#include "boyer_moore.h"

#include <iostream>

// Constructor. Save pattern and shiftTable
// assumption that the alphabet contains no more than 256 symbols
BoyerMoore::BoyerMoore(const std::string &pattern) : pattern(pattern) {
    shiftTable = std::vector<std::size_t>(256, pattern.size());
    if (pattern.empty()) {
        return;
    }
    for (std::size_t i = 0; i < pattern.size() - 1; i++) {
        shiftTable[pattern[i]] = pattern.size() - 1 - i;
    }
}

std::vector<std::size_t> BoyerMoore::search(const std::string &text) const {
    std::vector<std::size_t> result;
    auto n = text.size();
    auto m = pattern.size();

    // check for empty pattern and pattern bigger than text
    if (m == 0 || n < m) {
        return result;
    }

    std::size_t i = 0;
    while (i <= n - m) {
        std::size_t j = m;

        // Compare the pattern characters from right to left with the corresponding text characters
        while (j > 0 && pattern[j - 1] == text[i + j - 1]) {
            j--;
        }

        // If a match is found, record the occurrence and move to the next position in the text
        if (j == 0) {
            result.push_back(i);
            i++;
        } else {  // Move i by the shift amount based on the last character of the current window
            i += shiftTable[text[i + m - 1]];
        }
    }

    return result;
}
