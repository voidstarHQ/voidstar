#include <Scene.hh>
#include <Scene2D.hh>
#include <Scene3D.hh>

void
Scene::load(std::shared_ptr<Algorithm> algo) {
    if (type_ != algo->sceneType())
        throw std::runtime_error("Invalid algo for scene");
    if (algo_ && algo_ != algo) {
        std::cerr << "deleting algo" << std::endl;
        delete algo_;
    }
    algo_ = algo;
}

void
Scene::unload() {
}

void
Scene::reload() {
}

#define SCENE(Body) [](std::shared_ptr<Manager> manager) -> std::shared_ptr<Scene> { Body }
using SceneFactoryFunc = std::function<std::shared_ptr<Scene>(std::shared_ptr<Manager>)>;
std::map<SceneType, SceneFactoryFunc> scenes = {
    {SCENE_2D, SCENE( return std::make_shared<Scene2D>(); )},
    {SCENE_3D, SCENE( return std::make_shared<Scene3D>(); )},
};

std::shared_ptr<Scene>
Scene::forAlgo(std::shared_ptr<Manager> manager, std::shared_ptr<Algorithm> algo) {
    auto it = scenes.find(algo->sceneType());
    if (it == scenes.end()) {
        throw std::runtime_error("Unknown scene type for algorithm");
    }
    auto scene = it->second(manager);
    scene->init(manager->args());
    scene->load(algo);
    return scene;
}
