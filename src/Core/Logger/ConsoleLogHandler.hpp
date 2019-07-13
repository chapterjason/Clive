//
// Created by jason on 13.07.19.
//

#ifndef CLIVE_CONSOLELOGHANDLER_HPP
#define CLIVE_CONSOLELOGHANDLER_HPP

#include "LogHandlerInterface.hpp"

namespace Clive::Core {
    class ConsoleLogHandler : public LogHandlerInterface {

        protected:
            static std::string getTimeAsString();

        public:
            void log(LogLevel level, std::string message) override;
    };
}
#endif //CLIVE_CONSOLELOGHANDLER_HPP
