#include "kmp.h"

KMP::KMP(const std::string &pattern) : pattern(pattern) { computeLongestPrefixSuffixArray(); }

void KMP::computeLongestPrefixSuffixArray() {
    auto m = pattern.size();
    lps.resize(m, 0);
    std::size_t j = 0;

    for (std::size_t i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = lps[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        lps[i] = j;
    }
}

std::vector<std::size_t> KMP::search(const std::string &text) const {
    std::vector<std::size_t> result;
    auto n = text.size();
    auto m = pattern.size();
    std::size_t j = 0;

//  case with empty pattern
    if (m == 0) {
        return result;
    }

    for (std::size_t i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = lps[j - 1];
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            result.push_back(i - m + 1);
            j = lps[j - 1];
        }
    }

    return result;
}
