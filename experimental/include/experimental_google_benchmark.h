#ifndef SUBSTRING_LIBRARY_EXPERIMENTAL_GOOGLE_BENCHMARK_H
#define SUBSTRING_LIBRARY_EXPERIMENTAL_GOOGLE_BENCHMARK_H

#include <benchmark/benchmark.h>

#include <functional>

#include "benchmark_manager.h"
#include "experimental_base.h"

class ExperimentalGoogleBenchmark : public ExperimentalBase {
   private:
    template <AlgorithmType algorithmType>
    void RegisterType(const std::string &class_name, std::size_t textSize, std::size_t patternSize) {
        ::benchmark::RegisterBenchmark(("BM_Naive_Algorithm_Type_" + class_name).c_str(),
                                       RunNaiveSearch<algorithmType>);
        ::benchmark::RegisterBenchmark(("BM_Random_Latin_Algorithm_Type_" + class_name).c_str(),
                                       RunRandomSearch<algorithmType, CharsetTypes::LATIN>)
            ->Args({(long)textSize, (long)patternSize});
        ::benchmark::RegisterBenchmark(("BM_Random_Binary_Algorithm_Type_" + class_name).c_str(),
                                       RunRandomSearch<algorithmType, CharsetTypes::BINARY>)
            ->Args({(long)textSize, (long)patternSize});
    }

   public:
    explicit ExperimentalGoogleBenchmark(const std::vector<std::pair<std::size_t, std::size_t>> &sizes)
        : ExperimentalBase(sizes) {}

    template <AlgorithmType algorithmType>
    static void RunNaiveSearch(::benchmark::State &state) {
        for (auto _ : state) {
            MakeNaiveSearch<algorithmType>();
        }
    }

    template <AlgorithmType algorithmType, CharsetTypes charsetType>
    static void RunRandomSearch(::benchmark::State &state) {
        size_t textSize = state.range(0);
        size_t patternSize = state.range(1);
        for (auto _ : state) {
            MakeRandomSearch<algorithmType, charsetType>(textSize, patternSize);
        }
    }

    void RunExperiments() override {
        for (auto [textSize, patternSize] : random_sizes) {
            RegisterType<AlgorithmType::KMP>("KMP", textSize, patternSize);
            RegisterType<AlgorithmType::BOYER_MOORE>("Boyer-Moore", textSize, patternSize);
            RegisterType<AlgorithmType::RABIN_KARP>("Rabin-Karp", textSize, patternSize);
            RegisterType<AlgorithmType::SUFFIX_ARRAY>("Suffix-Array", textSize, patternSize);
            RegisterType<AlgorithmType::Z_ALGORITHM>("Z-Algorithm", textSize, patternSize);
            RegisterType<AlgorithmType::NOT_SO_NAIVE>("Not-so-naive", textSize, patternSize);
        }

        ::benchmark::RunSpecifiedBenchmarks();
    }
};

#endif  // SUBSTRING_LIBRARY_EXPERIMENTAL_GOOGLE_BENCHMARK_H
