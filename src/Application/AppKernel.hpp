//
// Created by jason on 18.07.19.
//

#ifndef CLIVE_APPKERNEL_HPP
#define CLIVE_APPKERNEL_HPP

#include "../Core/Kernel/Kernel.hpp"

using namespace Clive::Core;

namespace Clive::Application {
    class AppKernel : public Kernel {

        public:
            void bootstrap() override;

            int execute(int argc, char **argv) override;
    };
}

#endif //CLIVE_APPKERNEL_HPP
