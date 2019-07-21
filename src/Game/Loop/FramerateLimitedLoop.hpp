//
// Created by jason on 21.07.19.
//

#ifndef CLIVE_FRAMERATELIMITEDLOOP_HPP
#define CLIVE_FRAMERATELIMITEDLOOP_HPP

#include "Loop.hpp"

namespace Clive::Game {
    class FramerateLimitedLoop : public Loop {

        public:
            explicit FramerateLimitedLoop(const std::shared_ptr<sf::RenderWindow> &window);

            void run(double targetDelta) override;

    };
}

#endif //CLIVE_FRAMERATELIMITEDLOOP_HPP
