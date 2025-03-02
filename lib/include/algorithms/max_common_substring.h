#ifndef SUBSTRING_LIB_MAX_COMMON_SUBSTRING_H
#define SUBSTRING_LIB_MAX_COMMON_SUBSTRING_H

#include <string>
#include <vector>

class MaxCommonSubstring {
   public:
    explicit MaxCommonSubstring(const std::string &text);
    [[nodiscard]] std::vector<std::size_t> search(const std::string &pattern) const;

   private:
    std::string text;
};

#endif  // SUBSTRING_LIB_MAX_COMMON_SUBSTRING_H
