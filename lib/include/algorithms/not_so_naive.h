#ifndef SUBSTRING_LIB_NOT_SO_NAIVE_H
#define SUBSTRING_LIB_NOT_SO_NAIVE_H

#include <string>
#include <vector>

// Class for substring searching using Not So Naive Algorithm

class NotSoNaive {
   public:
    explicit NotSoNaive(const std::string &pattern);
    [[nodiscard]] std::vector<std::size_t> search(const std::string &pattern) const;

   private:
    [[nodiscard]] std::vector<std::size_t> naiveSearch(const std::string &pattern) const;

    std::string text;
};

#endif  // SUBSTRING_LIB_NOT_SO_NAIVE_H
