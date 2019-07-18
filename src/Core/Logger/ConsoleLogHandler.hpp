//
// Created by jason on 13.07.19.
//

#ifndef CLIVE_CONSOLELOGHANDLER_HPP
#define CLIVE_CONSOLELOGHANDLER_HPP

#include "LogHandlerInterface.hpp"
#include "../Format/TimeFormatInterface.hpp"
#include <memory>

namespace Clive::Core {
    class ConsoleLogHandler : public LogHandlerInterface {
        protected:
            std::shared_ptr<TimeFormatInterface> timeFormat;

        public:
            explicit ConsoleLogHandler(const std::shared_ptr<TimeFormatInterface> &timeFormat);

            void log(LogLevel level, std::string const &message) override;
    };
}
#endif //CLIVE_CONSOLELOGHANDLER_HPP
