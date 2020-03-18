#include "voidstar/managers/manager.h"

#include <iostream>

REGISTRY_IMPLEMENTATION_FOR(Manager);
REGISTER_META("managers", Manager);

void Manager::loadScene(std::shared_ptr<Scene> scene) {
  // XXX delete scene prior to creating a new one
  if (scene_) {
    std::cout << "deleting scene" << std::endl;
  }
  scene_ = scene;
  scene->init(args_);
}

void Manager::loadFile(const std::string& filename) {
  args_->paths.push_back(filename);
  loadFile(args_->paths.size() - 1);
}

bool Manager::loadFile(size_t index) {
  if (fileIndex_ == index && scene_) return true;

  fileIndex_ = index;
  // TODO: remove previous loader instance from scene.
  //       properly define who owns the variable and its lifetime.
  auto loader = Loader::fromURI(args_->paths[index]);
  if (!loader) args_->paths[index].erase(fileIndex_);
  if (args_->paths[index].empty()) return false;

  loader->load();
  auto range = DataRange::create(args_->range_begin, args_->range_end);

  if (scene_) {
    auto algo = scene_->algorithm();
    algo->use(loader, range);
    scene_->reload();
  } else {
    std::cerr << "Picked algo: " << args_->algo << std::endl;
    auto algoFactory = RegisteredAlgorithm(args_->algo);
    assert(algoFactory != nullptr);
    auto algo = algoFactory();
    algo->use(loader, range);
    auto sceneFactory = RegisteredScene(algo->sceneType());
    assert(sceneFactory);
    loadScene(sceneFactory(args_, algo));
  }
  return true;
}
