#ifndef SUBSTRING_LIB_RABINKARP_H
#define SUBSTRING_LIB_RABINKARP_H

#include <string>
#include <vector>

// Class for substring searching using Rabin Karp algorithm

class RabinKarp {
   public:
    explicit RabinKarp(const std::string &pattern);
    [[nodiscard]] std::vector<std::size_t> search(const std::string &text) const;

   private:
    std::vector<std::size_t> computeZFunction(std::string &text) const;

    const std::string pattern;
};

#endif  // SUBSTRING_LIB_RABIN_KARP_H
