//
// Created by jason on 17.07.19.
//

#ifndef CLIVE_FILELOGHANDLER_HPP
#define CLIVE_FILELOGHANDLER_HPP

#include "LogHandlerInterface.hpp"
#include "../Config/ConfigManagerInterface.hpp"
#include "../Format/TimeFormatInterface.hpp"

namespace Clive::Core {
    class FileLogHandler : public LogHandlerInterface {

        protected:
            std::shared_ptr<TimeFormatInterface> timeFormat;

            std::shared_ptr<ConfigManagerInterface> configManager;

        public:
            explicit FileLogHandler(const std::shared_ptr<TimeFormatInterface> &timeFormat,
                                    const std::shared_ptr<ConfigManagerInterface> &configManager);

            void log(LogLevel level, std::string const &message) override;

    };
}

#endif //CLIVE_FILELOGHANDLER_HPP
