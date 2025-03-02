#include "max_common_substring.h"

MaxCommonSubstring::MaxCommonSubstring(const std::string &text) : text(text) {}

std::vector<std::size_t> MaxCommonSubstring::search(const std::string &pattern) const {
    std::vector<std::size_t> result;
    std::size_t n = text.size(), m = pattern.size();

    if (m == 0 || m > n) {
        return result;  // Нет смысла искать пустой или слишком длинный шаблон
    }

    for (std::size_t i = 0; i <= n - m; ++i) {
        if (text.substr(i, m) == pattern) {
            result.push_back(i);
        }
    }

    return result;
}
