//
// Created by jason on 17.07.19.
//

#ifndef CLIVE_TIMEFORMATCONFIG_HPP
#define CLIVE_TIMEFORMATCONFIG_HPP

#include <string>
#include <yaml-cpp/yaml.h>

namespace Clive::Core {

    struct TimeFormatConfig {
        std::string format;
    };

}

namespace YAML {
    template<>
    struct convert<Clive::Core::TimeFormatConfig> {
        static Node encode(const Clive::Core::TimeFormatConfig &config) {
            Node node;

            node["format"] = config.format;

            return node;
        }

        static bool decode(const Node &node, Clive::Core::TimeFormatConfig &config) {
            if (!node.IsMap()) {
                return false;
            }

            config.format = node["format"].as<std::string>();

            return true;
        }
    };
}

#endif //CLIVE_TIMEFORMATCONFIG_HPP
