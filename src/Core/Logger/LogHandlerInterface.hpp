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
             * Log method that will receive the message from the LoggerInterface
             * @param level The verbosity level
             * @param message The message to log
             */
            virtual void log(LogLevel level, std::string const &message) = 0;
    };
}

#endif //CLIVE_LOGHANDLERINTERFACE_HPP
