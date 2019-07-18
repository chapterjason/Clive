//
// Created by jason on 17.07.19.
//

#ifndef CLIVE_TIMEFORMATINTERFACE_HPP
#define CLIVE_TIMEFORMATINTERFACE_HPP

#include <string>
#include <chrono>

namespace Clive::Core {
    class TimeFormatInterface {
        public:
            virtual ~TimeFormatInterface() = default;

            virtual std::string format() = 0;

            virtual std::string format(std::string const &format) = 0;

            virtual std::string
            format(std::string const &format, std::chrono::time_point<std::chrono::system_clock> const &time) = 0;
    };
}

#endif //CLIVE_TIMEFORMATINTERFACE_HPP
