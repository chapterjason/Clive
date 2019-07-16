#include <iostream>
#include "Core/Logger/LoggerInterface.hpp"
#include "Core/Logger/Logger.hpp"
#include "Core/Logger/ConsoleLogHandler.hpp"
#include <ContainerBuilder.h>

using namespace Clive::Core;
using namespace Hypodermic;

int main() {

    ContainerBuilder builder;

    builder.registerType< Clive::Core::Logger >().as< LoggerInterface >();
    builder.registerType< ConsoleLogHandler >().as< LogHandlerInterface >();

    auto container = builder.build();

//    LoggerInterface *logger;
//    LogHandlerInterface *logHandler;
//
//    logger = new Logger();
//    logHandler = new ConsoleLogHandler();
//
//    logger->addHandler("default", logHandler);
//
//    logger->setVerbosity(LogLevel::Fatal);
//
//    logger->info("test");
//
//    delete logger;

    return 0;
}