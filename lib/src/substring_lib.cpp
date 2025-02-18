#include "substring_lib.h"

#include <stdexcept>

#include "boyer_moore.h"
#include "kmp.h"
#include "not_so_naive.h"
#include "rabin_karp.h"
#include "suffix_array.h"
#include "z_algorithm.h"

std::vector<std::size_t> search_pattern(const std::string &text, const std::string &pattern, AlgorithmType type) {
    switch (type) {
        case AlgorithmType::KMP:
            return KMP(pattern).search(text);
        case AlgorithmType::BOYER_MOORE:
            return BoyerMoore(pattern).search(text);
        case AlgorithmType::Z_ALGORITHM:
            return ZAlgorithm(pattern).search(text);
        case AlgorithmType::SUFFIX_ARRAY:
            return SuffixArray(text).search(pattern);
        case AlgorithmType::RABIN_KARP:
            return RabinKarp(pattern).search(text);
        case AlgorithmType::NOT_SO_NAIVE:
            return NotSoNaive(text).search(pattern);
        default:
            throw std::invalid_argument("Unknown algorithm type");
    }
}
