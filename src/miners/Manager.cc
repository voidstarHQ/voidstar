#include <Manager.hh>
#include <GlfwManager.hh>

std::map<std::string, ManagerFactoryFunc> managers = {
    { "glfw", [](Arguments *args) { return new GlfwManager(args); } },
};

