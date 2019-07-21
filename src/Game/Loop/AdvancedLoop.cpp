//
// Created by jason on 21.07.19.
//

#include "AdvancedLoop.hpp"
#include "../../Core/Time.hpp"

using namespace Clive::Core;

namespace Clive::Game {

    void AdvancedLoop::run(double targetDelta) {
        double nextTime = Time::asSeconds();
        while (this->window->isOpen()) {
            double currentTime = Time::asSeconds();

            this->input();

            if (currentTime >= nextTime) {
                nextTime += targetDelta;
                this->update(targetDelta);
                if (currentTime < nextTime) {
                    this->draw();
                }
            } else {
                int sleepTime = (int) (1000.0 * (nextTime - currentTime));
                if (sleepTime > 0) {
                    sf::sleep(sf::milliseconds(sleepTime));
                }
            }
        }
    }

    AdvancedLoop::AdvancedLoop(const std::shared_ptr<sf::RenderWindow> &window) : Loop(window) {

    }
}
