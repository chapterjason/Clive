#include <iostream>
#include "Core/Logger/LoggerInterface.hpp"
#include "Core/Logger/Logger.hpp"
#include "Core/Logger/ConsoleLogHandler.hpp"

using namespace Clive::Core;

int main() {

    LoggerInterface *logger;
    LogHandlerInterface *logHandler;

    logger = new Logger();
    logHandler = new ConsoleLogHandler();

    logger->addHandler("default", logHandler);

    logger->setVerbosity(LogLevel::Fatal);

    logger->info("test");

    delete logger;

    return 0;
}