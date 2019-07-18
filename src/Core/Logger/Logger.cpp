//
// Created by jason on 13.07.19.
//

#include "Logger.hpp"

#include <algorithm>

namespace Clive::Core {
    void Logger::addHandler(const std::shared_ptr<LogHandlerInterface> &handler) {
        this->handlers.push_back(handler);
    }

    void Logger::removeHandler(const std::shared_ptr<LogHandlerInterface> &handler) {
        auto iterator = std::remove(this->handlers.begin(), this->handlers.end(), handler);
        this->handlers.erase(iterator);
    }

    void Logger::fatal(std::string const &message) {
        if (this->verbosity >= LogLevel::Fatal) {
            this->log(LogLevel::Fatal, message);
        }
    }

    void Logger::error(std::string const &message) {
        if (this->verbosity >= LogLevel::Error) {
            this->log(LogLevel::Error, message);
        }

    }

    void Logger::warn(std::string const &message) {
        if (this->verbosity >= LogLevel::Warn) {
            this->log(LogLevel::Warn, message);

        }
    }

    void Logger::info(std::string const &message) {
        if (this->verbosity >= LogLevel::Info) {
            this->log(LogLevel::Info, message);

        }
    }

    void Logger::debug(std::string const &message) {
        if (this->verbosity >= LogLevel::Debug) {
            this->log(LogLevel::Debug, message);

        }
    }

    void Logger::trace(std::string const &message) {
        if (this->verbosity >= LogLevel::Trace) {
            this->log(LogLevel::Trace, message);
        }
    }

    void Logger::log(LogLevel level, std::string const &message) {
        for (auto &handler : this->handlers) {
            handler->log(level, message);
        }
    }

    void Logger::setVerbosity(LogLevel level) {
        this->verbosity = level;
    }

    LogLevel Logger::getVerbosity() {
        return this->verbosity;
    }

    Logger::Logger(const std::vector<std::shared_ptr<LogHandlerInterface>> &handlers) {
        this->handlers = handlers;
    }

    void Logger::debug(int const &number) {
        this->debug(std::to_string(number));
    }

    void Logger::debug(float const &number) {
        this->debug(std::to_string(number));
    }

    void Logger::debug(double const &number) {
        this->debug(std::to_string(number));
    }
}
