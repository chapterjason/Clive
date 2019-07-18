//
// Created by jason on 17.07.19.
//

#ifndef CLIVE_CONFIGMANAGER_HPP
#define CLIVE_CONFIGMANAGER_HPP

#include "ConfigManagerInterface.hpp"

namespace Clive::Core {
    class ConfigManager : public ConfigManagerInterface {
        protected:
            std::map<std::string, YAML::Node> cache;

            YAML::Node load(std::string const &file);

        public:
            ConfigManager();

            YAML::Node get(std::string const &file) override;

    };
}

#endif //CLIVE_CONFIGMANAGER_HPP
