#ifndef SUBSTRING_LIB_Z_FUNCTION_H
#define SUBSTRING_LIB_Z_FUNCTION_H

#include <string>
#include <vector>

// Class for substring searching using Z algorithm
// assumption that the alphabet does not contain "#" symbol

class ZAlgorithm {
   public:
    explicit ZAlgorithm(const std::string &pattern);
    [[nodiscard]] std::vector<std::size_t> search(const std::string &text) const;

   private:
    [[nodiscard]] std::vector<std::size_t> computeZFunction(std::string &text) const;

    const std::string pattern;
};

#endif  // SUBSTRING_LIB_Z_FUNCTION_H
