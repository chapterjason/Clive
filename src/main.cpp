
#include <memory>
#include "Application/AppKernel.hpp"

using namespace Clive::Core;
using namespace Clive::Application;

int main(int argc, char *argv[]) {

    std::shared_ptr<KernelInterface> kernel = std::make_shared<AppKernel>();

    kernel->bootstrap();
    kernel->execute(argc, argv);

    return 0;
}