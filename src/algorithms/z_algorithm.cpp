#include "z_algorithm.h"


// Constractor saves pattern
ZAlgorithm::ZAlgorithm(const std::string &pattern) : pattern(pattern){}

// function to compute Z-function
std::vector<std::size_t> ZAlgorithm::computeZFunction (std::string &s) const {
    std::vector<std::size_t> result(s.size(), 0);

    std::size_t left = 0, right = 0;
    for (std::size_t i = 1; i < s.size(); i++) {
        // if the symbol has already been encountered
        // initialise result[i - l] but no further than the right pointer
        if (i <= right)
            result[i] = std::min(right - i + 1, result[i - left]);

        // each successful increase of result[i] will shift the z-block by one unit
        while (i + result[i] < s.size() && s[result[i]] == s[i + result[i]])
            result[i]++;

        // check if we are to the right of the current z-block
        if (i + result[i] - 1 > right) {
            right = i + result[i] - 1;
            left = i;
        }
    }
    return result;
}

std::vector<std::size_t> ZAlgorithm::search(const std::string &text) const {
    std::string s = pattern + '#' + text;
    auto zFunction = computeZFunction(s);
    auto n = text.size();
    auto m = pattern.size();

    std::vector<std::size_t> result;
    for (int i = m + 1; i < s.size(); ++i){
        // in positions where the value of the zFunction is equal to |pattern| = m,
        // the substring that matches the pattern starts.
        if (zFunction[i] == m) {
            result.push_back(i - m - 1);
        }
    }
    return result;
}
