//
// Created by Arina on 1/21/25.
//

#include "substring_lib.h"
#include "kmp.h"
#include "iostream"

std::vector<int> search_pattern(const std::string& text, const std::string& pattern, AlgorithmType type) {
    switch (type) {
        case AlgorithmType::KMP:
            return KMP(pattern).search(text);
        default:
            throw std::invalid_argument("Unknown algorithm type");
    }
}
