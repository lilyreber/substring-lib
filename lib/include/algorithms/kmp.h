#ifndef KMP_H
#define KMP_H

#include <string>
#include <vector>

// The KMP algorithm searches for a pattern in a text using the
// LPS array to skip unnecessary comparisons, achieving O(n + m) time complexity.
class KMP {
   public:
    explicit KMP(const std::string &pattern);
    std::vector<std::size_t> search(const std::string &text) const;

   private:
    // for each prefix compute the size of the longest prefix equal suffix
    void computeLongestPrefixSuffixArray();

    std::string pattern;
    std::vector<std::size_t> longestPrefixSuffix;
};

#endif  // KMP_H
