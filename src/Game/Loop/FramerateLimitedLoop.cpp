//
// Created by jason on 21.07.19.
//

#include "FramerateLimitedLoop.hpp"
#include "../../Core/Time.hpp"
#include <SFML/System.hpp>

using namespace Clive::Core;

namespace Clive::Game {

    void FramerateLimitedLoop::run(double targetDelta) {
        double nextTime = Time::asSeconds();
        while (this->window->isOpen()) {
            double currentTime = Time::asSeconds();

            this->input();

            if (currentTime >= nextTime) {
                nextTime += targetDelta;
                this->update(targetDelta);
                this->draw();
            } else {
                int sleepTime = (int) (1000.0 * (nextTime - currentTime));
                if (sleepTime > 0) {
                    sf::sleep(sf::milliseconds(sleepTime));
                }
            }
        }

    }

    FramerateLimitedLoop::FramerateLimitedLoop(const std::shared_ptr<sf::RenderWindow> &window) : Loop(window) {

    }
}
