//
// Created by jason on 17.07.19.
//

#ifndef CLIVE_TIMEFORMAT_HPP
#define CLIVE_TIMEFORMAT_HPP

#include "TimeFormatInterface.hpp"
#include "../Config/ConfigManagerInterface.hpp"

namespace Clive::Core {
    class TimeFormat : public TimeFormatInterface {

        protected:
            std::shared_ptr<ConfigManagerInterface> configManager;

            static std::string applyMilliseconds(std::string const &format,
                                                 std::chrono::time_point<std::chrono::system_clock> const &time);

        public:
            explicit TimeFormat(const std::shared_ptr<ConfigManagerInterface> &configManager);

            std::string format() override;

            std::string format(std::string const &format) override;

            std::string
            format(std::string const &format, std::chrono::time_point<std::chrono::system_clock> const &time) override;

    };
}

#endif //CLIVE_TIMEFORMAT_HPP
