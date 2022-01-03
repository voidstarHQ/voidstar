#include "voidstar/scenes/scene.h"
#include "voidstar/size2str.h"

REGISTRY_IMPLEMENTATION_FOR(Scene)

void Scene::load(std::shared_ptr<Algorithm> algo) {
  if (type_ != algo->sceneType())
    throw std::runtime_error("Invalid algo for scene");
  if (algo_ && algo_ != algo) std::cerr << "deleting algo\n";
  algo_ = algo;
}

void Scene::resize(u32 viewport_width, u32 viewport_height) {
  const float aspect_ratio =
      static_cast<float>(viewport_width) / static_cast<float>(viewport_height);
  std::cout << "aspect: " << aspect_ratio << " (" << size2str(viewport_width)
            << 'x' << size2str(viewport_height) << ")\n";
}
