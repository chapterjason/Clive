//
// Created by jason on 13.07.19.
//

#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include "ConsoleLogHandler.hpp"

namespace Clive::Core {

    void ConsoleLogHandler::log(LogLevel level, std::string const &message) {
        std::cout << "[" << this->timeFormat->format() << "][" << level << "] " << message << std::endl;
    }

    ConsoleLogHandler::ConsoleLogHandler(const std::shared_ptr<TimeFormatInterface> &timeFormat) {
        this->timeFormat = timeFormat;
    }

}
