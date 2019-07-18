//
// Created by jason on 18.07.19.
//

#ifndef CLIVE_STATEINTERFACE_HPP
#define CLIVE_STATEINTERFACE_HPP

#include <memory>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace Clive::Game {

    class StateInterface {

        public:
            virtual void init() = 0;

            virtual void cleanup() = 0;

            virtual void pause() = 0;

            virtual void resume() = 0;

            virtual void input(const sf::Event &event) = 0;

            virtual void update(double delta) = 0;

            virtual void draw(std::shared_ptr<sf::RenderWindow> window) = 0;

    };

}

#endif //CLIVE_STATEINTERFACE_HPP
