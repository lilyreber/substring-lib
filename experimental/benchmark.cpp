#include <benchmark/benchmark.h>

#include <functional>
#include <iostream>
#include <memory>
#include <vector>

#include "config_loader.h"
#include "experimental_easy.h"
#include "experimental_google_benchmark.h"
#include "substring_lib.h"

/*
 *  Config:
 *  - should contain array "random_sizes" with pairs of elements
 *  - each pair specify "textSize" and "patternSize"
 */
int main(int argc, char *argv[]) {
    try {
        std::string config_filename = "/configs/config.json";
        if (argc == 2) {
            config_filename = argv[1];
        } else if (argc > 2) {
            throw std::runtime_error(
                "Error: to many arguments.\nUsage: ./benchmark "
                "<config.json>");
        }

        std::vector<std::pair<std::size_t, std::size_t>> test_sizes =
            ConfigLoader::loadConfig(PROJECT_ROOT + config_filename);

        // can be run separately for better measures
        ExperimentalGoogleBenchmark experimentalGoogleBenchmark(test_sizes);
        experimentalGoogleBenchmark.RunExperiments();
        ExperimentalEasy experimentalEasy(test_sizes);
        experimentalEasy.RunExperiments();
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}