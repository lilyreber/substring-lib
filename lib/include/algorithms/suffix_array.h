#ifndef SUBSTRING_LIB_SUFFIX_ARRAY_H
#define SUBSTRING_LIB_SUFFIX_ARRAY_H

#include <string>
#include <vector>

// Class for substring searching using the Suffix Array and binary search

class SuffixArray {
   public:
    explicit SuffixArray(const std::string &text);
    std::vector<std::size_t> search(const std::string &pattern) const;

   private:
    std::vector<std::size_t> buildSuffixArray(const std::string &text) const;

    std::size_t lowerBound(const std::string &pattern) const;
    std::size_t upperBound(const std::string &pattern) const;

    const std::string text;
    std::vector<std::size_t> suffixArray;
};

#endif  // SUBSTRING_LIB_SUFFIX_ARRAY_H
