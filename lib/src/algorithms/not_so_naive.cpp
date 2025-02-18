#include <iostream>
#include <string>
#include <vector>
#include "not_so_naive.h"

NotSoNaive::NotSoNaive(const std::string &text) : text(text){}

// Naive search if pattern size is 1
std::vector<std::size_t> NotSoNaive::naiveSearch(const std::string &pattern) const {
    std::vector<std::size_t> result;
    int n = text.size();
    const char charPattern = pattern[0];

    for (int i = 0; i < n; ++i) {
        if (text[i] == charPattern) {
            result.push_back(i);
        }
    }
    return result;
}


std::vector<std::size_t> NotSoNaive::search(const std::string &pattern) const {
    int n = text.size();
    int m = pattern.size();
    std::vector<std::size_t> result;

    if (m > n || m == 0) {
        return result;
    }

    if (m == 1) {
        return naiveSearch(pattern);
    }

    int shift_on_mismatch, shift_on_match;

    // define the shift steps
    if (pattern[0] == pattern[1]) {
        // the shift steps if the first two characters match
        shift_on_mismatch = 2;
        shift_on_match = 1;
    } else {
        // the shift steps if the first two characters do not match
        shift_on_mismatch = 1;
        shift_on_match = 2;
    }

    // occurrence search
    int i = 0;
    while (i <= n - m) {
        if (text[i + 1] != pattern[1]) {
            // the shift the pattern by k positions
            i += shift_on_mismatch;
        } else {
            // check the rest pattern
            if (pattern.substr(2, m - 2) == text.substr(i + 2, m - 2) && text[i] == pattern[0]) {
                //
                result.push_back(i);
            }
            // the shift the pattern by l positions
            i += shift_on_match;
        }
    }
    return result;
}
