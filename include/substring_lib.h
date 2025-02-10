#ifndef SUBSTRING_LIB_SUBLIB_H
#define SUBSTRING_LIB_SUBLIB_H

#include <string>
#include <vector>

enum class AlgorithmType { KMP, BOYER_MOORE };

std::vector<std::size_t> search_pattern(const std::string &text, const std::string &pattern, AlgorithmType type);

#endif  // SUBSTRING_LIB_SUBLIB_H
