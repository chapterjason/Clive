//
// Created by jason on 21.07.19.
//

#include "Time.hpp"

namespace Clive::Core {

    double Time::asNanoseconds() {
        auto time = std::chrono::high_resolution_clock::now().time_since_epoch();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(time).count();
    }

    double Time::asMicroseconds() {
        return Time::asNanoseconds() / 1000.0;
    }

    double Time::asMilliseconds() {
        return Time::asMicroseconds() / 1000.0;
    }

    double Time::asSeconds() {
        return Time::asMilliseconds() / 1000.0;
    }
}
