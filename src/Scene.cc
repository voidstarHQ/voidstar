#include <iostream>

#include <Scene.hh>
#include <Scene2D.hh>
#include <Scene3D.hh>

void Scene::load(Algorithm* algo)
{
    if (type_ != algo->sceneType())
        throw std::runtime_error("Invalid algo for scene");
    if (algo_ && algo_ != algo) {
        std::cerr << "deleting algo" << std::endl;
        delete algo_;
    }
    algo_ = algo;
}

void Scene::unload()
{
}

void Scene::reload()
{
}

#define SCENE(Body) [](Manager* manager) -> Scene* { Body }
using SceneFactoryFunc = std::function<Scene*(Manager*)>;
std::map<SceneType, SceneFactoryFunc> scenes = {
    { SCENE_2D, SCENE( return new Scene2D(manager); ) },
    { SCENE_3D, SCENE( return new Scene3D(manager); ) },
};

Scene*
Scene::forAlgo(Manager* manager, Algorithm* algo)
{
    auto it = scenes.find(algo->sceneType());
    if (it == scenes.end()) {
        throw std::runtime_error("Unknown scene type for algorithm");
    }
    auto* scene = it->second(manager);
    scene->init();
    scene->load(algo);
    return scene;
}
