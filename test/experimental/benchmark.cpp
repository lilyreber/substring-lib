#include <iostream>

#include "substring_lib.h"

int main() {
    auto kmp_res = search_pattern("aabaabcabbcabc", "abc", AlgorithmType::KMP);
    std::cout << "kmp_res_size: " << kmp_res.size() << "\n";
    std::cout << "kmp_res_0: " << kmp_res[0] << "\n"
              << "kmp_res_1: " << kmp_res[1] << "\n";

    auto bm_res = search_pattern("aabaabcabbcabc", "abc", AlgorithmType::BOYER_MOORE);
    std::cout << "bm_res_size: " << bm_res.size() << "\n";
    std::cout << "bm_res_0: " << bm_res[0] << "\n"
              << "bm_res_1: " << bm_res[1] << "\n";

    auto z_res = search_pattern("aabaabcabbcabc", "abc", AlgorithmType::Z_FUNCTION);
    std::cout << "z_res_size: " << z_res.size() << "\n";
    std::cout << "z_res_0: " << z_res[0] << "\n"
              << "z_res_1: " << z_res[1] << "\n";
}
