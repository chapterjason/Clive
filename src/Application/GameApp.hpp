#include <memory>

//
// Created by jason on 17.07.19.
//

#ifndef CLIVE_GAME_HPP
#define CLIVE_GAME_HPP

#include <chrono>
#include <memory>
#include <random>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "../Core/Logger/LoggerInterface.hpp"
#include "../Game/State/StateManagerInterface.hpp"
#include "../Game/Loop/ExpertLoop.hpp"

using namespace Clive::Core;
using namespace Clive::Game;

namespace Clive::Application {
    class GameApp : public ExpertLoop {
        protected:
            std::shared_ptr<StateManagerInterface> stateManager;

        public:
            GameApp(const std::shared_ptr<sf::RenderWindow> &window,
                    const std::shared_ptr<StateManagerInterface> &stateManager);

            void input() override;

            void update(double delta) override;

            void draw() override;

    };
}

#endif //CLIVE_GAME_HPP
