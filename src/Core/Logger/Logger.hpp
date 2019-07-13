//
// Created by jason on 13.07.19.
//

#ifndef CLIVE_LOGGER_HPP
#define CLIVE_LOGGER_HPP

#include "LoggerInterface.hpp"
#include <map>

namespace Clive::Core {
    class Logger : public LoggerInterface {
        protected:
            std::map<std::string, LogHandlerInterface *> *handlers;

            LogLevel verbosity;

        public:

            Logger();

            ~Logger() override;

            void addHandler(std::string name, LogHandlerInterface *handler) override;

            void removeHandler(std::string name) override;

            void fatal(std::string message) override;

            void error(std::string message) override;

            void warn(std::string message) override;

            void info(std::string message) override;

            void debug(std::string message) override;

            void trace(std::string message) override;

            void log(LogLevel level, std::string message) override;

            void setVerbosity(LogLevel level) override;

            LogLevel getVerbosity() override;

    };
}

#endif //CLIVE_LOGGER_HPP
