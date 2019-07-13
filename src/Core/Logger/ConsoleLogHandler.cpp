//
// Created by jason on 13.07.19.
//

#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include "ConsoleLogHandler.hpp"

namespace Clive::Core {
    // 2017/10/16 23:08:46.479|DEBUG|
    void ConsoleLogHandler::log(LogLevel level, std::string message) {

        std::cout << ConsoleLogHandler::getTimeAsString() << "|" << level << "|" << message << std::endl;
    }

    std::string ConsoleLogHandler::getTimeAsString() {
        auto now = std::chrono::system_clock::now();

        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
        auto timer = std::chrono::system_clock::to_time_t(now);
        std::tm brokenTime = *std::localtime(&timer);
        std::ostringstream outputStringStream;

        outputStringStream << std::put_time(&brokenTime, "%Y/%m/%d %H:%M:%S"); // HH:MM:SS
        outputStringStream << "." << std::setfill('0') << std::setw(3) << milliseconds.count();

        return outputStringStream.str();
    }

}
