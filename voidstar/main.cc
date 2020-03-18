#include "voidstar/algorithm.h"
#include "voidstar/arguments.h"
#include "voidstar/managers/manager.h"
#include "voidstar/scenes/scene.h"

int main(int argc, char* argv[]) {
  auto args = parseArgs(argc, argv);
  if (!args) {
    return 0;
  }

  auto managerFactory = RegisteredManager(args->manager);
  if (!managerFactory) {
    std::cerr << "unknown manager " << args->manager << std::endl;
    return 1;
  }
  auto manager = managerFactory(args);
  manager->init();
  if (!manager->loadFile(0)) {
    std::cerr << "no usable paths\n";
    return 1;
  }
  manager->run();

  return 0;
}
