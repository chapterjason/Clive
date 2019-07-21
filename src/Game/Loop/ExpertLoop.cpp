//
// Created by jason on 21.07.19.
//

#include "ExpertLoop.hpp"
#include "../../Core/Time.hpp"

using namespace Clive::Core;

namespace Clive::Game {

    void ExpertLoop::run(double targetDelta) {
        double maxTimeDiff = 0.5;
        int maxSkippedFrames = 5;

        int skippedFrames = 1;
        double nextTime = Time::asSeconds();
        while (this->window->isOpen()) {
            double currentTime = Time::asSeconds();
            double diffTime = currentTime - nextTime;

            if (diffTime > maxTimeDiff) {
                nextTime = currentTime;
            }

            this->input();

            if (currentTime >= nextTime) {
                nextTime += targetDelta;

                this->update(targetDelta);

                if ((currentTime < nextTime) || (skippedFrames > maxSkippedFrames)) {
                    this->draw();
                    skippedFrames = 1;
                } else {
                    skippedFrames++;
                }
            } else {
                int sleepTime = (int) (1000.0 * (nextTime - currentTime));
                if (sleepTime > 0) {
                    sf::sleep(sf::milliseconds(sleepTime));
                }
            }
        }

    }

    ExpertLoop::ExpertLoop(const std::shared_ptr<sf::RenderWindow> &window) : Loop(window) {
    }
}
