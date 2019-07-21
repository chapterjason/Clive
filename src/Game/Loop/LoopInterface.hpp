//
// Created by jason on 21.07.19.
//

#ifndef CLIVE_LOOPINTERFACE_HPP
#define CLIVE_LOOPINTERFACE_HPP

namespace Clive::Game {

    class LoopInterface {
        public:

            virtual void input() = 0;

            virtual void update(double delta) = 0;

            virtual void draw() = 0;

            virtual void run(double targetDelta) = 0;

    };

}

#endif //CLIVE_LOOPINTERFACE_HPP
