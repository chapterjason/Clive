//
// Created by jason on 21.07.19.
//

#include "Loop.hpp"

namespace Clive::Game {

    void Loop::run(double targetDelta) {
        while (this->window->isOpen()) {
            this->input();
            this->update(targetDelta);
            this->draw();
        }
    }

    Loop::Loop(const std::shared_ptr<sf::RenderWindow> &window) {
        this->window = window;
    }
}
