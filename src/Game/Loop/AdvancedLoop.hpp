//
// Created by jason on 21.07.19.
//

#ifndef CLIVE_ADVANCEDLOOP_HPP
#define CLIVE_ADVANCEDLOOP_HPP

#include "Loop.hpp"

namespace Clive::Game {
    class AdvancedLoop : public Loop {

        public:
            explicit AdvancedLoop(const std::shared_ptr<sf::RenderWindow> &window);

            void run(double targetDelta) override;

    };
}

#endif //CLIVE_ADVANCEDLOOP_HPP
