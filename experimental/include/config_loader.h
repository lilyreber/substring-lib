#ifndef CONFIG_LOADER_H
#define CONFIG_LOADER_H

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <stdexcept>
#include <vector>

/*
 *  Parameters:
 *  - filename: absolute path to config file
 *
 *  Config:
 *  - should contain array "random_sizes" with pairs of elements
 *  - each pair specify "textSize" and "patternSize"
 */
class ConfigLoader {
   public:
    static std::vector<std::pair<std::size_t, std::size_t>> loadConfig(const std::string &filepath) {
        std::ifstream file(filepath);
        if (!file) {  // if file can't be open throw runtime_error
            throw std::runtime_error("Error: Failed to open config file: " + filepath);
        }

        nlohmann::json config;  // read json config
        file >> config;

        // check that config contains array "random_sizes"
        if (!config.contains("random_sizes") || !config["random_sizes"].is_array()) {
            throw std::runtime_error(
                "Error: Invalid config format. 'random_sizes' array is missing "
                "or "
                "incorrect.");
        }

        // convert json structure to std::vector<std::pair<std::size_t, std::size_t>>
        return config["random_sizes"].get<std::vector<std::pair<std::size_t, std::size_t>>>();
    }
};

#endif  // CONFIG_LOADER_H