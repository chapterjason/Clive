//
// Created by jason on 18.07.19.
//

#ifndef CLIVE_KERNEL_HPP
#define CLIVE_KERNEL_HPP

#include <Hypodermic.h>
#include "KernelInterface.hpp"

using namespace Hypodermic;

namespace Clive::Core {
    class Kernel : public KernelInterface {

        protected:
            ContainerBuilder builder;

            std::shared_ptr<Container> container;

        public:
            Kernel();

            void bootstrap() override;

            int execute(int argc, char **argv) override;

    };
}

#endif //CLIVE_KERNEL_HPP
