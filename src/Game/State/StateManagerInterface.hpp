//
// Created by jason on 18.07.19.
//

#ifndef CLIVE_STATEMANAGERINTERFACE_HPP
#define CLIVE_STATEMANAGERINTERFACE_HPP

#include <memory>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "./StateInterface.hpp"

namespace Clive::Game {

    class StateManagerInterface {

        public:

            virtual void change(const std::shared_ptr<StateInterface> &state) = 0;

            virtual void push(const std::shared_ptr<StateInterface> &state) = 0;

            virtual void pop() = 0;

            virtual void input(const sf::Event &event) = 0;

            virtual void update(double delta) = 0;

            virtual void draw(std::shared_ptr<sf::RenderWindow> window) = 0;

    };

}

#endif //CLIVE_STATEMANAGERINTERFACE_HPP
