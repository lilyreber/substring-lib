//
// Created by Arina on 1/21/25.
//

#ifndef SUBSTRING_LIB_SUBLIB_H
#define SUBSTRING_LIB_SUBLIB_H

#include <string>
#include <vector>

enum class AlgorithmType {
    KMP
};

std::vector<int> search_pattern(const std::string& text, const std::string& pattern, AlgorithmType type);

#endif //SUBSTRING_LIB_SUBLIB_H
