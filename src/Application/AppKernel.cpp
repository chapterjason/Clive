//
// Created by jason on 18.07.19.
//

#include "AppKernel.hpp"
#include "../Core/Logger/LoggerInterface.hpp"
#include "../Core/Logger/LogHandlerInterface.hpp"
#include "../Core/Logger/ConsoleLogHandler.hpp"
#include "../Core/Config/ConfigManagerInterface.hpp"
#include "../Core/Format/TimeFormatInterface.hpp"
#include "../Game/State/StateManager.hpp"
#include "../Game/State/StateManagerInterface.hpp"
#include "../Core/Config/ConfigManager.hpp"
#include "../Core/Format/TimeFormat.hpp"
#include "../Core/Logger/Logger.hpp"
#include "GameApp.hpp"

using namespace Clive::Core;
using namespace Clive::Game;

namespace Clive::Application {

    void AppKernel::bootstrap() {

        this->builder.registerType<Clive::Core::Logger>().as<LoggerInterface>();
        this->builder.registerType<ConsoleLogHandler>().as<LogHandlerInterface>();
//    builder.registerType<FileLogHandler>().as<LogHandlerInterface>();

        this->builder.registerType<ConfigManager>().as<ConfigManagerInterface>();
        this->builder.registerType<TimeFormat>().as<TimeFormatInterface>();
        this->builder.registerType<StateManager>().as<StateManagerInterface>();

        this->builder.registerInstanceFactory([](ComponentContext &) {
            return std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Konfetti Simulator 2019");
        });

        this->builder.registerType<GameApp>();

        Kernel::bootstrap();
    }

    int AppKernel::execute(int argc, char **argv) {
        auto app = this->container->resolve<GameApp>();

        double targetOperationPerSecond = 1.f / 60.f;

        try {
            app->run(targetOperationPerSecond);
        } catch (...) {
            return 1;
        }

        return 0;
    }
}
