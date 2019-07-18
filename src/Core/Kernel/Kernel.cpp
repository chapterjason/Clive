//
// Created by jason on 18.07.19.
//

#include "Kernel.hpp"

namespace Clive::Core {

    void Kernel::bootstrap() {
        this->container = this->builder.build();
    }

    int Kernel::execute(int argc, char **argv) {
        return 0;
    }

    Kernel::Kernel() {
        this->builder = ContainerBuilder();
    }
}