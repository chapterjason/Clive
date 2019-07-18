//
// Created by jason on 17.07.19.
//

#include "GameApp.hpp"
#include "State/GameState.hpp"

namespace Clive::Application {

    GameApp::GameApp(const std::shared_ptr<sf::RenderWindow> &window,
                     const std::shared_ptr<StateManagerInterface> &stateManager) {
        this->stateManager = stateManager;
        this->window = window;
    }

    void GameApp::input() {
        sf::Event event{};
        while (this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->window->close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::F1) {
                    this->stateManager->change(std::make_shared<GameState>());
                }
            }

            this->stateManager->input(event);
        }
    }

    void GameApp::update(double delta) {

        // update the stuff
        this->stateManager->update(delta);

    }

    void GameApp::draw() {
        this->window->clear(sf::Color::Black);

        // render stuff to window
        this->stateManager->draw(this->window);

        this->window->display();
    }

    void GameApp::run(double delta) {
        double maxTimeDiff = 0.5;
        int skippedFrames = 1;
        int maxSkippedFrames = 5;

        double nextTime = GameApp::getTime();
        while (this->window->isOpen()) {
            double currentTime = GameApp::getTime();
            double diffTime = currentTime - nextTime;

            if (diffTime > maxTimeDiff) {
                nextTime = currentTime;
            }

            if (currentTime >= nextTime) {
                // assign the time for the next update
                nextTime += delta;

                this->input();
                this->update(delta);

                if ((currentTime < nextTime) || (skippedFrames > maxSkippedFrames)) {
                    this->draw();
                    skippedFrames = 1;
                } else {
                    skippedFrames++;
                }
            } else {
                // calculate the time to sleep
                int sleepTime = (int) (1000.0 * (nextTime - currentTime));
                if (sleepTime > 0) {
                    sf::sleep(sf::milliseconds(sleepTime));
                }
            }
        }

    }
}