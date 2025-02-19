#ifndef SUBSTRING_LIBRARY_EXPERIMENTAL_BASE_H
#define SUBSTRING_LIBRARY_EXPERIMENTAL_BASE_H

#include <vector>
#include "benchmark_utils.h"
#include "substring_lib.h"

class ExperimentalBase {
protected:
    std::vector<std::pair<std::size_t, std::size_t>> random_sizes;

    template <AlgorithmType algorithmType>
    static void MakeNaiveSearch() {
        std::string text = "hello world, this is a test string";
        std::string pattern = "test";
        search_pattern(text, pattern, algorithmType);
    }

    template <AlgorithmType algorithmType, CharsetTypes charsetType>
    static void MakeRandomSearch(std::size_t textSize, std::size_t patternSize) {
        RandomStringGenerator generator;
        std::string text = generator.getRandomString(textSize, charsetType);
        std::string pattern = generator.getRandomString(patternSize, charsetType);
        search_pattern(text, pattern, algorithmType);
    }

public:
    explicit ExperimentalBase(std::vector<std::pair<std::size_t, std::size_t>> sizes)
            : random_sizes(std::move(sizes)) {
    }

    virtual void RunExperiments() = 0;

    virtual ~ExperimentalBase() = default;
};


#endif //SUBSTRING_LIBRARY_EXPERIMENTAL_BASE_H
