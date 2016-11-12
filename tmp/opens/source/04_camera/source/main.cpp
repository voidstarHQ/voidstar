#include <iostream>
#include <functional>
#include <string>
#include <map>

#include "Arguments.hh"
#include "Manager.hh"
#include "GlfwManager.hh"
#include "Scene.hh"

// could be hidden in Manager.hh that would be the place to add further
// managers
using ManagerFactoryFunc = std::function<Manager*(Arguments*)>;
static std::map<std::string, ManagerFactoryFunc> managers = {
    { "glfw", [](Arguments *args) { return new GlfwManager(args); } },
};

int main(int argc, char *argv[])
{
    auto *args = parseArgs(argc, argv);
    auto *manager = managers[args->manager](args);
    try {
        manager->init();
        auto scene = new Scene(manager);
        scene->init();
        //scene->loadData(...)
        manager->loadScene(scene);
        manager->run();
    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
