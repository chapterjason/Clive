//
// Created by jason on 13.07.19.
//

#ifndef CLIVE_LOGGERINTERFACE_HPP
#define CLIVE_LOGGERINTERFACE_HPP

#include <string>
#include <memory>
#include "LogLevel.hpp"
#include "LogHandlerInterface.hpp"

namespace Clive::Core {
    class LoggerInterface {
        public:

            virtual ~LoggerInterface() = default;

            /**
             * Something bad happened; application is going down
             * @param message The message that will be forwarded to all the log handler, in fatal level
             */
            virtual void fatal(std::string const &message) = 0;

            /**
             * Something failed; application may or may not continue
             * @param message The message that will be forwarded to all the log handler, in error level
             */
            virtual void error(std::string const &message) = 0;

            /**
             * Something unexpected; application will continue
             * @param message The message that will be forwarded to all the log handler, in warn level
             */
            virtual void warn(std::string const &message) = 0;

            /**
             * Normal behavior like mail sent, user updated profile etc.
             * @param message The message that will be forwarded to all the log handler, in info level
             */
            virtual void info(std::string const &message) = 0;

            /**
             * For debugging; executed query, user authenticated, session expired
             * @param message The message that will be forwarded to all the log handler, in debug level
             */
            virtual void debug(std::string const &message) = 0;

            virtual void debug(int const &number) = 0;

            virtual void debug(float const &number) = 0;

            virtual void debug(double const &number) = 0;

            /**
             * For trace debugging; begin method X, end method X
             * @param message The message that will be forwarded to all the log handler, in trace level
             */
            virtual void trace(std::string const &message) = 0;

            /**
             * Base log method
             *
             * @param level In which level this message will be logged
             * @param message The message that will be forwarded to all the log handler
             */
            virtual void log(LogLevel level, std::string const &message) = 0;

            /**
             * Set the verbosity
             *
             * @param level The verbosity level
             */
            virtual void setVerbosity(LogLevel level) = 0;

            /**
             * Get the current verbosity
             * @return The verbosity level
             */
            virtual LogLevel getVerbosity() = 0;

            /**
             * Add a log handler to the logger
             * @param handler The log handler
             */
            virtual void addHandler(const std::shared_ptr<LogHandlerInterface> &handler) = 0;

            /**
             * Removes a log handler from the logger
             * @param handler The log handler
             */
            virtual void removeHandler(const std::shared_ptr<LogHandlerInterface> &handler) = 0;
    };
}

#endif //CLIVE_LOGGERINTERFACE_HPP
