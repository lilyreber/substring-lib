#include "suffix_array.h"
#include <algorithm>
#include <iostream>

// Constructor to initialize the suffix array
SuffixArray::SuffixArray(const std::string& text) : text(text) { 
    suffixArray = buildSuffixArray(text); 
}

// Function to build the suffix array using a doubling technique and sorting
std::vector<std::size_t> SuffixArray::buildSuffixArray(const std::string& text) const {
    std::size_t n = text.size();
    std::vector<std::size_t> sa(n), rank(n), temp(n);

    // Initialize suffix array and ranks based on characters
    for (std::size_t i = 0; i < n; i++) {
        sa[i] = i;
        rank[i] = text[i];
    }

    // Double the length of substrings at each step
    for (std::size_t len = 1; len < n; len *= 2) {
        auto cmp = [&](std::size_t i, std::size_t j) {
            if (rank[i] != rank[j]) return rank[i] < rank[j];
            std::size_t ri = (i + len < n) ? rank[i + len] : -1;
            std::size_t rj = (j + len < n) ? rank[j + len] : -1;
            return ri >= rj;
        };

        // Use stable_sort to maintain the correct order of suffixes
        std::stable_sort(sa.begin(), sa.end(), cmp);

        // Recalculate ranks after sorting
        temp[sa[0]] = 0;
        for (std::size_t i = 1; i < n; i++) {
            temp[sa[i]] = temp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        }
        rank = temp;
    }

    return sa;  // Return the built suffix array
}

// Binary search to find the lower bound (first occurrence of the pattern)
std::size_t SuffixArray::lowerBound(const std::string& pattern) const {
    std::size_t left = 0, right = text.size();
    while (left < right) {
        std::size_t mid = left + (right - left) / 2;
        std::size_t idx = suffixArray[mid];

        // Compare the pattern with the suffix starting at suffixArray[mid]
        if (text.compare(idx, pattern.size(), pattern) < 0) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

// Binary search to find the upper bound (first index where the pattern doesn't match)
std::size_t SuffixArray::upperBound(const std::string& pattern) const {
    std::size_t left = 0, right = text.size();
    while (left < right) {
        std::size_t mid = left + (right - left) / 2;
        std::size_t idx = suffixArray[mid];

        // Compare the pattern with the suffix starting at suffixArray[mid]
        if (text.compare(idx, pattern.size(), pattern) <= 0) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

// Search method for finding the pattern in the suffix array
std::vector<std::size_t> SuffixArray::search(const std::string& pattern) const {
    if (text.empty() || pattern.empty() || pattern.size() > text.size()) {
        return {};
    }
    std::size_t lb = lowerBound(pattern);
    std::size_t ub = upperBound(pattern);
    std::vector<std::size_t> result;

    // Collect the matching positions in the suffix array
    for (std::size_t i = lb; i < ub; i++) {
        result.push_back(suffixArray[i]);
    }
    return result;
}