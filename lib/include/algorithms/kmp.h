#ifndef KMP_H
#define KMP_H

#include <string>
#include <vector>

class KMP {
   public:
    explicit KMP(const std::string &pattern);
    std::vector<std::size_t> search(const std::string &text) const;

   private:
    void computeLongestPrefixSuffixArray();

    std::string pattern;
    std::vector<std::size_t> lps;
};

#endif  // KMP_H
