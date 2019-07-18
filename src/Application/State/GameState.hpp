//
// Created by jason on 18.07.19.
//

#ifndef CLIVE_GAMESTATE_HPP
#define CLIVE_GAMESTATE_HPP

#include <random>
#include "../../Game/State/StateInterface.hpp"

using namespace Clive::Game;

namespace Clive::Application {
    class GameState : public StateInterface {
        protected:
            std::vector<std::shared_ptr<sf::Shape>> shapes;

        public:
            int randomValueForColor();

            void input(const sf::Event &event) override;

            void update(double delta) override;

            void draw(std::shared_ptr<sf::RenderWindow> window) override;

            // @todo implement basic init and cleanup (running flag) in a State class

            void init() override;

            void cleanup() override;

            void pause() override;

            void resume() override;

    };
}

#endif //CLIVE_GAMESTATE_HPP
