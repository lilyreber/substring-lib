#ifndef SUBSTRING_LIB_BOYER_MOORE_H
#define SUBSTRING_LIB_BOYER_MOORE_H

#include <string>
#include <vector>

// Class for algorithm Boyer-Moore
// assumption that the alphabet contains no more than 256 symbols

class BoyerMoore {
   public:
    explicit BoyerMoore(const std::string &pattern);
    [[nodiscard]] std::vector<std::size_t> search(const std::string &text) const;

   private:
    std::string pattern;
    std::vector<std::size_t> shiftTable;
};

#endif  // SUBSTRING_LIB_BOYER_MOORE_H
