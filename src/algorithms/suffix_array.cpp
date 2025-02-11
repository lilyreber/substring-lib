#include "suffix_array.h"

#include <algorithm>
#include <iostream>

// Constructor to initialize the suffix array
SuffixArray::SuffixArray(const std::string& text) : text(text) { suffixArray = buildSuffixArray(text); }

// Function to build the suffix array using a doubling technique and sorting
std::vector<int> SuffixArray::buildSuffixArray(const std::string& text) const {
    int n = text.size();
    std::vector<int> sa(n), rank(n), temp(n);

    // Initialize suffix array and ranks based on characters
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        rank[i] = text[i];
    }

    // Double the length of substrings at each step
    for (int len = 1; len < n; len *= 2) {
        auto cmp = [&](int i, int j) {
            if (rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = (i + len < n) ? rank[i + len] : -1;
            int rj = (j + len < n) ? rank[j + len] : -1;
            return ri < rj;
        };

        // Use stable_sort to maintain the correct order of suffixes
        std::stable_sort(sa.begin(), sa.end(), cmp);

        // Recalculate ranks after sorting
        temp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            temp[sa[i]] = temp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        }
        rank = temp;
    }

    return sa;  // Return the built suffix array
}

// Binary search to find the lower bound (first occurrence of the pattern)
int SuffixArray::lowerBound(const std::string& pattern) const {
    int left = 0, right = text.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        std::string suffix = text.substr(suffixArray[mid]);
        if (suffix.compare(0, pattern.size(), pattern) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

// Binary search to find the upper bound (first index where the pattern doesn't match)
int SuffixArray::upperBound(const std::string& pattern) const {
    int left = 0, right = text.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        std::string suffix = text.substr(suffixArray[mid]);
        if (suffix.compare(0, pattern.size(), pattern) <= 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

// Search method for finding the pattern in the suffix array
std::vector<int> SuffixArray::search(const std::string& pattern) const {
    int lb = lowerBound(pattern);
    int ub = upperBound(pattern);
    std::vector<int> result;

    // Collect the matching positions in the suffix array
    for (int i = lb; i < ub; i++) {
        result.push_back(suffixArray[i]);
    }
    return result;
}