//
// Created by jason on 17.07.19.
//

#include "TimeFormat.hpp"
#include "TimeFormatConfig.hpp"

#include <sstream>
#include <iomanip>
#include <iostream>
#include <regex>

namespace Clive::Core {

    std::string
    TimeFormat::format(std::string const &format, std::chrono::time_point<std::chrono::system_clock> const &time) {
        std::locale locale;
        auto timer = std::chrono::system_clock::to_time_t(time);
        const auto &putFormat = std::use_facet<std::time_put<char> >(locale);
        std::tm brokenTime = *std::localtime(&timer);
        std::ostringstream outputStringStream;

        std::string formatted = TimeFormat::applyMilliseconds(format, time);
        putFormat.put(outputStringStream, outputStringStream, ' ', &brokenTime, formatted.data(),
                      formatted.data() + formatted.length());

        return outputStringStream.str();
    }

    std::string TimeFormat::applyMilliseconds(std::string const &format,
                                              std::chrono::time_point<std::chrono::system_clock> const &time) {
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(time.time_since_epoch()) % 1000;
        std::stringstream millisecondStream;

        millisecondStream << std::setfill('0') << std::setw(3) << milliseconds.count();
        std::string millisecondsString = millisecondStream.str();
        return std::regex_replace(format, std::regex("%s"), millisecondsString);
    }

    std::string TimeFormat::format() {
        auto timeConfig = this->configManager->getAs<TimeFormatConfig>("config.yaml", "time");

        return this->format(timeConfig.format);
    }

    std::string TimeFormat::format(std::string const &format) {
        return this->format(format, std::chrono::system_clock::now());
    }

    TimeFormat::TimeFormat(const std::shared_ptr<ConfigManagerInterface> &configManager) {
        this->configManager = configManager;
    }

}