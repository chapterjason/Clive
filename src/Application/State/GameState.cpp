//
// Created by jason on 18.07.19.
//

#include "GameState.hpp"

namespace Clive::Application {

    void GameState::input(const sf::Event &event) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                std::shared_ptr<sf::CircleShape> ball = std::make_shared<sf::CircleShape>(10.f);
                ball->setOrigin(5.f, 5.f);
                ball->setPosition(event.mouseButton.x, event.mouseButton.y);

                ball->setFillColor(sf::Color(this->randomValueForColor(), this->randomValueForColor(),
                                             this->randomValueForColor()));

                this->shapes.push_back(ball);
            }
        }
    }

    void GameState::update(double delta) {
    }

    void GameState::draw(std::shared_ptr<sf::RenderWindow> window) {
        for (auto &shape : this->shapes) {
            window->draw(*shape);
        }
    }

    int GameState::randomValueForColor() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> random(50, 255);
        return random(rng);
    }

    void GameState::init() {
        this->shapes = std::vector<std::shared_ptr<sf::Shape>>();
    }

    void GameState::cleanup() {
        this->shapes.clear();
    }

    void GameState::pause() {
    }

    void GameState::resume() {
    }
}
