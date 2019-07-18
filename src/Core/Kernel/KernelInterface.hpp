//
// Created by jason on 18.07.19.
//

#ifndef CLIVE_KERNELINTERFACE_HPP
#define CLIVE_KERNELINTERFACE_HPP

namespace Clive::Core {

    class KernelInterface {
        public:
            virtual ~KernelInterface() = default;

            virtual void bootstrap() = 0;

            virtual int execute(int argc, char *argv[]) = 0;

    };

}

#endif //CLIVE_KERNELINTERFACE_HPP
