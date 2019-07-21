//
// Created by jason on 21.07.19.
//

#ifndef CLIVE_LOOP_HPP
#define CLIVE_LOOP_HPP

#include "LoopInterface.hpp"
#include <memory>
#include <SFML/Graphics.hpp>

namespace Clive::Game {
    class Loop : public LoopInterface {
        protected:
            std::shared_ptr<sf::RenderWindow> window;

        public:
            explicit Loop(const std::shared_ptr<sf::RenderWindow> &window);

            void run(double targetDelta) override;
    };
}
#endif //CLIVE_LOOP_HPP
