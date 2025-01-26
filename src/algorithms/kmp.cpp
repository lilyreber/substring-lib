#include "kmp.h"

KMP::KMP(const std::string& pattern) : pattern(pattern) {
    computeLPS();
}

void KMP::computeLPS() {
    int m = pattern.size();
    lps.resize(m, 0);
    int j = 0;

    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = lps[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        lps[i] = j;
    }
}

std::vector<int> KMP::search(const std::string& text) const {
    std::vector<int> result;
    int n = text.size();
    int m = pattern.size();
    int j = 0;

    if (m == 0) {
        return result;
    }

    for (int i = 0; i < n; ++i) {
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
