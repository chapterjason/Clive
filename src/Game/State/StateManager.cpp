//
// Created by jason on 18.07.19.
//

#include "StateManager.hpp"

namespace Clive::Game {

    void StateManager::change(const std::shared_ptr<StateInterface> &state) {
        if (!this->states.empty()) {
            states.back()->cleanup();
            states.pop_back();
        }

        // store and init the new state
        states.push_back(state);
        states.back()->init();
    }

    void StateManager::push(const std::shared_ptr<StateInterface> &state) {
        // pause current state
        if (!states.empty()) {
            states.back()->pause();
        }

        // store and init the new state
        states.push_back(state);
        states.back()->init();
    }

    void StateManager::pop() {
        // cleanup the current state
        if (!states.empty()) {
            states.back()->cleanup();
            states.pop_back();
        }

        // resume previous state
        if (!states.empty()) {
            states.back()->resume();
        }
    }

    void StateManager::input(const sf::Event &event) {
        for (auto &state : this->states) {
            state->input(event);
        }
    }

    void StateManager::update(double delta) {
        for (auto &state : this->states) {
            state->update(delta);
        }

    }

    void StateManager::draw(std::shared_ptr<sf::RenderWindow> window) {
        for (auto &state : this->states) {
            state->draw(window);
        }
    }
}