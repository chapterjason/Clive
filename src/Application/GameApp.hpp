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

using namespace Clive::Core;
using namespace Clive::Game;

namespace Clive::Application {
    class GameApp {

        protected:
            std::shared_ptr<StateManagerInterface> stateManager;

            std::shared_ptr<sf::RenderWindow> window;

        public:

            GameApp(const std::shared_ptr<sf::RenderWindow> &window,
                    const std::shared_ptr<StateManagerInterface> &stateManager);

            void input();

            void update(double delta);

            void draw();

            static double getTime() {
                auto time = std::chrono::high_resolution_clock::now().time_since_epoch();
                return std::chrono::duration_cast<std::chrono::nanoseconds>(time).count() / 1000000000.0;
            }

            // @see http://entropyinteractive.com/2011/02/game-engine-design-the-game-loop/
            // @todo implement GameLoopInterface
            // @todo implement GameLoop
            // @todo implement FramerateLimitedGameLoop
            // @todo implement AdvancedGameLoop
            // @todo implement ExpertGameLoop

            /**
             * Begin the game loop
             * @param delta time between logic updates (in seconds)
             */
            void run(double delta);

    };
}

#endif //CLIVE_GAME_HPP
