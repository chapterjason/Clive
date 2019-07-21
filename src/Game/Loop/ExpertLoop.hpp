//
// Created by jason on 21.07.19.
//

#ifndef CLIVE_EXPERTLOOP_HPP
#define CLIVE_EXPERTLOOP_HPP

#include "Loop.hpp"

namespace Clive::Game {
    class ExpertLoop : public Loop {
        public:
            explicit ExpertLoop(const std::shared_ptr<sf::RenderWindow> &window);

            void run(double targetDelta) override;
    };
}

#endif //CLIVE_EXPERTLOOP_HPP
