#include <iostream>
#include <functional>
#include <string>
#include <map>

#include <Arguments.hh>
#include <Algorithm.hh>
#include <FileLoader.hh>
#include <MmapLoader.hh>
#include <Manager.hh>
#include <Range.hh>
#include <Scene.hh>
#include <Scene2D.hh>
#include <Scene3D.hh>

int
main(int argc, char* argv[]) {
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
    manager->loadFile(0);
    manager->run();

    return 0;
}
