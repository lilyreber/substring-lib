#ifndef SUBSTRING_LIB_SUBLIB_H
#define SUBSTRING_LIB_SUBLIB_H

#include <string>
#include <vector>

// store algorithm types
enum class AlgorithmType { KMP };

// common, public for library function
std::vector<std::size_t> search_pattern(const std::string &text, const std::string &pattern, AlgorithmType type);

#endif  // SUBSTRING_LIB_SUBLIB_H
