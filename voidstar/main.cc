#include <functional>
#include <iostream>
#include <map>
#include <string>

#include "src/include/Algorithm.h"
#include "src/include/Arguments.h"
#include "src/include/DataRange.h"
#include "src/include/FileLoader.h"
#include "src/include/Manager.h"
#include "src/include/MmapLoader.h"
#include "src/include/Scene.h"
#include "src/include/Scene2D.h"
#include "src/include/Scene3D.h"

int main(int argc, char* argv[]) {
  auto args = parseArgs(argc, argv);
  if (!args) {
    return 0;
  }

  auto manager = createManager(args->manager, args);
  if (!manager) {
    std::cerr << "unknown manager " << args->manager << std::endl;
    return 1;
  }
  manager->init();
  if (!manager->loadFile(0)) {
    std::cerr << "no usable paths\n";
    return 1;
  }
  manager->run();

  return 0;
}
