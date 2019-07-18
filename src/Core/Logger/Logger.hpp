//
// Created by jason on 13.07.19.
//

#ifndef CLIVE_LOGGER_HPP
#define CLIVE_LOGGER_HPP

#include "LoggerInterface.hpp"
#include <map>
#include <memory>
#include <vector>

namespace Clive::Core {
    class Logger : public LoggerInterface {
        protected:
            std::vector<std::shared_ptr<LogHandlerInterface>> handlers;

            LogLevel verbosity = LogLevel::Debug;

        public:

            explicit Logger(const std::vector<std::shared_ptr<LogHandlerInterface> > &handlers);

            void addHandler(const std::shared_ptr<LogHandlerInterface> &handler) override;

            void removeHandler(const std::shared_ptr<LogHandlerInterface> &handler) override;

            void fatal(std::string const &message) override;

            void error(std::string const &message) override;

            void warn(std::string const &message) override;

            void info(std::string const &message) override;

            void debug(std::string const &message) override;

            void debug(int const &number) override;

            void debug(float const &number) override;

            void debug(double const &number) override;

            void trace(std::string const &message) override;

            void log(LogLevel level, std::string const &message) override;

            void setVerbosity(LogLevel level) override;

            LogLevel getVerbosity() override;

    };
}

#endif //CLIVE_LOGGER_HPP
