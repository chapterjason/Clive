//
// Created by jason on 13.07.19.
//

#include "Logger.hpp"

namespace Clive::Core {
    void Logger::addHandler(std::string name, LogHandlerInterface *handler) {
        this->handlers->insert(std::pair<std::string, LogHandlerInterface *>(name, handler));
    }

    void Logger::removeHandler(std::string name) {
        auto iterator = this->handlers->find(name);

        if (iterator != this->handlers->end()) {
            this->handlers->erase(name);
        }
    }

    void Logger::fatal(std::string message) {
        if (this->verbosity >= LogLevel::Fatal) {
            this->log(LogLevel::Fatal, message);
        }
    }

    void Logger::error(std::string message) {
        if (this->verbosity >= LogLevel::Error) {
            this->log(LogLevel::Error, message);
        }

    }

    void Logger::warn(std::string message) {
        if (this->verbosity >= LogLevel::Warn) {
            this->log(LogLevel::Warn, message);

        }
    }

    void Logger::info(std::string message) {
        if (this->verbosity >= LogLevel::Info) {
            this->log(LogLevel::Info, message);

        }
    }

    void Logger::debug(std::string message) {
        if (this->verbosity >= LogLevel::Debug) {
            this->log(LogLevel::Debug, message);

        }
    }

    void Logger::trace(std::string message) {
        if (this->verbosity >= LogLevel::Trace) {
            this->log(LogLevel::Trace, message);
        }
    }

    void Logger::log(LogLevel level, std::string message) {
        for (auto &handler : *this->handlers) {
            handler.second->log(level, message);
        }
    }

    Logger::Logger() {
        this->verbosity = LogLevel::Info;
        this->handlers = new std::map<std::string, LogHandlerInterface *>();
    }

    void Logger::setVerbosity(LogLevel level) {
        this->verbosity = level;
    }

    LogLevel Logger::getVerbosity() {
        return this->verbosity;
    }

    Logger::~Logger() {
        delete this->handlers;
    }
}
