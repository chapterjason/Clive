//
// Created by jason on 17.07.19.
//

#ifndef CLIVE_FILELOGHANDLERCONFIG_HPP
#define CLIVE_FILELOGHANDLERCONFIG_HPP

#include <string>
#include <yaml-cpp/yaml.h>

namespace Clive::Core {

    struct FileLogHandlerConfig {
        std::string file;
    };

}

namespace YAML {
    template<>
    struct convert<Clive::Core::FileLogHandlerConfig> {
        static Node encode(const Clive::Core::FileLogHandlerConfig &config) {
            Node node;

            node["file"] = config.file;

            return node;
        }

        static bool decode(const Node &node, Clive::Core::FileLogHandlerConfig &config) {
            if (!node.IsMap()) {
                return false;
            }

            config.file = node["file"].as<std::string>();

            return true;
        }
    };
}

#endif //CLIVE_FILELOGHANDLERCONFIG_HPP
