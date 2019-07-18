//
// Created by jason on 17.07.19.
//

#include <yaml-cpp/yaml.h>
#include "ConfigManager.hpp"

namespace Clive::Core {

    YAML::Node ConfigManager::get(std::string const &file) {
        return this->load(file);
    }

    YAML::Node ConfigManager::load(std::string const &file) {
        auto iterator = this->cache.find(file);

        if (iterator != this->cache.end()) {
            return iterator->second;
        }

        YAML::Node node = YAML::LoadFile(file);

        this->cache.insert(std::pair<std::string, YAML::Node>(file, node));

        return node;
    }

    ConfigManager::ConfigManager() {
        this->cache = std::map<std::string, YAML::Node>();
    }

}