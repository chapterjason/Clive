//
// Created by jason on 13.07.19.
//

#ifndef CLIVE_LOGGERINTERFACE_HPP
#define CLIVE_LOGGERINTERFACE_HPP

#include <string>
#include "LogLevel.hpp"
#include "LogHandlerInterface.hpp"

namespace Clive::Core {
    class LoggerInterface {
        public:

            virtual ~LoggerInterface() = default;

            /**
             * Something bad happened; application is going down
             */
            virtual void fatal(std::string message) = 0;

            /**
             * Something failed; application may or may not continue
             */
            virtual void error(std::string message) = 0;

            /**
             * Something unexpected; application will continue
             */
            virtual void warn(std::string message) = 0;

            /**
             * Normal behavior like mail sent, user updated profile etc.
             */
            virtual void info(std::string message) = 0;

            /**
             * For debugging; executed query, user authenticated, session expired
             */
            virtual void debug(std::string message) = 0;

            /**
             * For trace debugging; begin method X, end method X
             */
            virtual void trace(std::string message) = 0;

            /**
             * Base log method
             */
            virtual void log(LogLevel level, std::string message) = 0;

            virtual void setVerbosity(LogLevel level) = 0;

            virtual LogLevel getVerbosity() = 0;

            virtual void addHandler(std::string name, LogHandlerInterface *handler) = 0;

            virtual void removeHandler(std::string name) = 0;
    };
}

#endif //CLIVE_LOGGERINTERFACE_HPP
