#ifndef SUBSTRING_LIBRARY_EXPERIMENTAL_EASY_H
#define SUBSTRING_LIBRARY_EXPERIMENTAL_EASY_H

#include <benchmark/benchmark.h>

#include <iostream>
#include <string>
#include <vector>

#include "benchmark_manager.h"
#include "experimental_base.h"

class ExperimentalEasy : public ExperimentalBase {
   private:
    // calculate metrics for naive search, random Latin and random binary texts
    template <AlgorithmType algorithmType>
    void RunExperiment(const std::string &experiment_name, std::size_t textSize, std::size_t patternSize) const {
        BenchmarkManager::Measure(experiment_name + "_Naive", MakeNaiveSearch<algorithmType>);
        BenchmarkManager::Measure(experiment_name + "_Random_Latin/" + "text_size=" + std::to_string(textSize) +
                                      "/pattern_size=" + std::to_string(patternSize),
                                  MakeRandomSearch<algorithmType, CharsetTypes::LATIN>, textSize, patternSize);
        BenchmarkManager::Measure(experiment_name + "_Random_Binary/" + "text_size=" + std::to_string(textSize) +
                                      "/pattern_size=" + std::to_string(patternSize),
                                  MakeRandomSearch<algorithmType, CharsetTypes::BINARY>, textSize, patternSize);
    }

   public:
    explicit ExperimentalEasy(const std::vector<std::pair<std::size_t, std::size_t>> &sizes)
        : ExperimentalBase(sizes) {}

    // Specify all algorithms which will be measured, for each pair of text-pattern sizes
    void RunExperiments() override {
        for (auto [textSize, patternSize] : random_sizes) {
            RunExperiment<AlgorithmType::KMP>("KMP", textSize, patternSize);
            RunExperiment<AlgorithmType::BOYER_MOORE>("Boyer-Moore", textSize, patternSize);
            RunExperiment<AlgorithmType::RABIN_KARP>("Rabin-Karp", textSize, patternSize);
            RunExperiment<AlgorithmType::SUFFIX_ARRAY>("Suffix-Array", textSize, patternSize);
            RunExperiment<AlgorithmType::Z_ALGORITHM>("Z-Algorithm", textSize, patternSize);
            RunExperiment<AlgorithmType::NOT_SO_NAIVE>("Not-so-naive", textSize, patternSize);
            RunExperiment<AlgorithmType::AHO_CORASICK>("Aho-Corasick", textSize, patternSize);
            RunExperiment<AlgorithmType::MAX_COMMON_SUBSTRING>("Max-common-substring", textSize, patternSize);
        }
    }
};

#endif  // SUBSTRING_LIBRARY_EXPERIMENTAL_EASY_H
