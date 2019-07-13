//
// Created by jason on 13.07.19.
//

#ifndef CLIVE_LOGLEVEL_HPP
#define CLIVE_LOGLEVEL_HPP

namespace Clive::Core {
    enum LogLevel {
        Off = 0,
        Info = 1,
        Warn = 2,
        Error = 3,
        Fatal = 4,
        Debug = 5,
        Trace = 6,
    };
}

#endif //CLIVE_LOGLEVEL_HPP
