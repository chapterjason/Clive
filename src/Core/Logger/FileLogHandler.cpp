//
// Created by jason on 17.07.19.
//

#include "FileLogHandler.hpp"
#include "FileLogHandlerConfig.hpp"
#include <fstream>

namespace Clive::Core {

    void FileLogHandler::log(LogLevel level, std::string const &message) {
        auto loggerConfig = this->configManager->getAs<FileLogHandlerConfig>("config.yaml", "logger");

        std::ofstream logFile;

        logFile.open(loggerConfig.file, std::ios_base::app);
        logFile << this->timeFormat->format() << "|" << level << "|" << message << std::endl;
    }

    FileLogHandler::FileLogHandler(const std::shared_ptr<TimeFormatInterface> &timeFormat,
                                   const std::shared_ptr<ConfigManagerInterface> &configManager) {
        this->configManager = configManager;
        this->timeFormat = timeFormat;
    }

}