#include "src/include/Scene.h"

#include "src/include/Scene2D.h"
#include "src/include/Scene3D.h"

void Scene::load(std::shared_ptr<Algorithm> algo) {
  if (type_ != algo->sceneType())
    throw std::runtime_error("Invalid algo for scene");
  if (algo_ && algo_ != algo) std::cerr << "deleting algo" << std::endl;
  algo_ = algo;
}

#define SCENE(Body) []() -> std::shared_ptr<Scene> { Body }
using SceneFactoryFunc = std::function<std::shared_ptr<Scene>()>;
std::map<SceneType, SceneFactoryFunc> scenes = {
    {SCENE_2D, SCENE(return std::make_shared<Scene2D>();)},
    {SCENE_3D, SCENE(return std::make_shared<Scene3D>();)},
};

std::shared_ptr<Scene> Scene::with_algo(std::shared_ptr<Arguments> args,
                                        std::shared_ptr<Algorithm> algo) {
  auto it = scenes.find(algo->sceneType());
  if (it == scenes.end()) {
    throw std::runtime_error("Unknown scene type for algorithm");
  }
  auto scene = it->second();
  scene->init(args);
  scene->load(algo);
  return scene;
}
