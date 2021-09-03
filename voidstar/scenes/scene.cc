#include "voidstar/scenes/scene.h"

REGISTRY_IMPLEMENTATION_FOR(Scene)

void Scene::load(std::shared_ptr<Algorithm> algo) {
  if (type_ != algo->sceneType())
    throw std::runtime_error("Invalid algo for scene");
  if (algo_ && algo_ != algo) std::cerr << "deleting algo\n";
  algo_ = algo;
}
