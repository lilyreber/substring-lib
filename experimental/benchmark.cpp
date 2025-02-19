#include <benchmark/benchmark.h>

#include <functional>
#include <iostream>
#include <memory>
#include <vector>

#include "config_loader.h"
#include "experimental_easy.h"
#include "experimental_google_benchmark.h"
#include "substring_lib.h"

// FIXME
// Конфиг должен содержать список размеров тестируемых наборов данных.
// Пример:
//
// ```
// {
//   "random_sizes": [10, 100, 10000]
// }
//```
//
// Здесь "random_sizes" — это массив, в котором указываются размеры входных
// данных, использующиеся для тестирования различных алгоритмов рандомными
// тестами.
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

        //        FIXME для Кати
        ExperimentalGoogleBenchmark experimentalGoogleBenchmark(test_sizes);  // comment for better result
        experimentalGoogleBenchmark.RunExperiments();                         // comment for better result
        ExperimentalEasy experimentalEasy(test_sizes);
        experimentalEasy.RunExperiments();
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}