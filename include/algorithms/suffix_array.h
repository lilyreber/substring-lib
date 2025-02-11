#ifndef SUBSTRING_LIB_SUFFIX_ARRAY_H
#define SUBSTRING_LIB_SUFFIX_ARRAY_H

#include <string>
#include <vector>

// Class for substring searching using the Suffix Array and binary search

class SuffixArray {
public:
    explicit SuffixArray(const std::string &text);
    std::vector<int> search(const std::string &pattern) const;

private:
    std::vector<int> buildSuffixArray(const std::string &text) const;

    int lowerBound(const std::string &pattern) const;
    int upperBound(const std::string &pattern) const;

    const std::string text;
    std::vector<int> suffixArray; 
};

#endif  // SUBSTRING_LIB_SUFFIX_ARRAY_H
