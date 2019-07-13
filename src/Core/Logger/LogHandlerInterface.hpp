//
// Created by jason on 13.07.19.
//

#ifndef CLIVE_LOGHANDLERINTERFACE_HPP
#define CLIVE_LOGHANDLERINTERFACE_HPP

#include <string>
#include "LogLevel.hpp"

namespace Clive::Core {
    class LogHandlerInterface {
        public:
            virtual ~LogHandlerInterface() = default;

            /**
             * Base log method
             */
            virtual void log(LogLevel level, std::string message) = 0;
    };
}

#endif //CLIVE_LOGHANDLERINTERFACE_HPP
