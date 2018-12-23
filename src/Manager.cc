#include <iostream>

#include <Manager.hh>
#include <GlfwManager.hh>

void
Manager::loadFile(const std::string& filename) {
    args_->paths.push_back(filename);
    loadFile(args_->paths.size() - 1);
}

bool
Manager::loadFile(size_t index) {
    if (fileIndex_ == index && scene_)
        return true;

    fileIndex_ = index;
    // TODO: remove previous loader instance from scene.
    //       properly define who owns the variable and its longevity
    auto loader = Loader::fromURI(args_->paths[index]);
    if (nullptr == loader)
        args_->paths[index].erase(fileIndex_);
    if (args_->paths[index].empty())
        return false;

    loader->load();
    auto range = DataRange::create(args_->range_begin, args_->range_end);

    if (scene_) {
        scene_->algorithm()->use(loader, range);
        scene_->reload();
        return true;
    }

    auto uglyhack_algo = createAlgorithm(args_->algo);
    if (auto algo = std::dynamic_pointer_cast<Algo3D>(uglyhack_algo)) {
        algo->use(loader, range);
        if (scene_) {
            std::cout << "deleting 3D scene" << std::endl;
        }
        scene_ = Scene::with_algo(args_, algo);
        scene_->init(args_);
        return true;
    }

    if (auto algo = std::dynamic_pointer_cast<Algo2D>(uglyhack_algo)) {
        algo->use(loader, range);
        if (scene_) {
            std::cout << "deleting 2D scene" << std::endl;
        }
        scene_ = Scene::with_algo(args_, algo);
        scene_->init(args_);
    }
    return true;
}

std::shared_ptr<Manager>
createManager(const std::string& str, std::shared_ptr<Arguments> args) {
    auto it = managers.find(str);
    if (it == managers.end()) {
        return NULL;
    }
    return it->second(args);
}

#define MANAGER(Body) [](std::shared_ptr<Arguments> args) { Body }
const std::map<const std::string, ManagerFactoryFunc> managers = {
    {"glfw", MANAGER( return GlfwManager::instance(args); )},
};
