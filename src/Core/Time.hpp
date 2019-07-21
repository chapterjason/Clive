//
// Created by jason on 21.07.19.
//

#ifndef CLIVE_TIME_HPP
#define CLIVE_TIME_HPP

#include <chrono>

namespace Clive::Core {
    class Time {
        public:
            static double asNanoseconds();

            static double asMicroseconds();

            static double asMilliseconds();

            static double asSeconds();
    };
}

#endif //CLIVE_TIME_HPP
