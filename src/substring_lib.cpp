#include "substring_lib.h"

#include <stdexcept>
#include "kmp.h"

std::vector<std::size_t> search_pattern(const std::string &text, const std::string &pattern, AlgorithmType type) {
    switch (type) {
        case AlgorithmType::KMP:
            return KMP(pattern).search(text);
        default:
            throw std::invalid_argument("Unknown algorithm type");
    }
}
