#include <iostream>

#include "substring_lib.h"

int main() {
    auto kmp_res = search_pattern("aabaabcabbcabc", "abc", AlgorithmType::KMP);
    std::cout << "kmp_res_size: " << kmp_res.size() << "\n";
    std::cout << "kmp_res_0: " << kmp_res[0] << "\n"
              << "kmp_res_1: " << kmp_res[1] << "\n";
}
