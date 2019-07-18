//
// Created by jason on 18.07.19.
//

#ifndef CLIVE_STATEMANAGER_HPP
#define CLIVE_STATEMANAGER_HPP

#include "StateManagerInterface.hpp"

namespace Clive::Game {
    class StateManager : public StateManagerInterface {

        protected:
            std::vector<std::shared_ptr<StateInterface>> states;

        public:
            void change(const std::shared_ptr<StateInterface> &state) override;

            void push(const std::shared_ptr<StateInterface> &state) override;

            void pop() override;

            void input(const sf::Event &event) override;

            void update(double delta) override;

            void draw(std::shared_ptr<sf::RenderWindow> window) override;

    };
}

#endif //CLIVE_STATEMANAGER_HPP
