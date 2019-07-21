//
// Created by jason on 17.07.19.
//

#include "GameApp.hpp"
#include "State/GameState.hpp"

namespace Clive::Application {

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

    GameApp::GameApp(const std::shared_ptr<sf::RenderWindow> &window,
                     const std::shared_ptr<StateManagerInterface> &stateManager) : ExpertLoop(window) {
        this->stateManager = stateManager;
    }

}