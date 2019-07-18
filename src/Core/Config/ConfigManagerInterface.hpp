//
// Created by jason on 17.07.19.
//

#ifndef CLIVE_CONFIGMANAGERINTERFACE_HPP
#define CLIVE_CONFIGMANAGERINTERFACE_HPP

#include <yaml-cpp/node/node.h>

namespace Clive::Core {
    class ConfigManagerInterface {
        public:
            /**
             * Get the config
             * @param file
             * @return
             */
            virtual YAML::Node get(std::string const &file) = 0;

            /**
             * Get a key as something
             * @param file
             * @param key
             * @return
             */
            template<typename T>
            T getAs(std::string const &file, std::string const &key) {
                YAML::Node config = this->get(file);
                return config[key].as<T>();
            }

    };
}

#endif //CLIVE_CONFIGMANAGERINTERFACE_HPP
