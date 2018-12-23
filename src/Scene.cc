#include <Scene.hh>
#include <Scene2D.hh>
#include <Scene3D.hh>

std::shared_ptr<Scene>
Scene::with_algo(const std::shared_ptr<Arguments> args, const std::shared_ptr<Algo2D> algo) {
    auto scene = std::make_shared<Scene2D>();
    scene->init(args);
    scene->load(algo);
    return scene;
}

std::shared_ptr<Scene>
Scene::with_algo(const std::shared_ptr<Arguments> args, const std::shared_ptr<Algo3D> algo) {
    auto scene = std::make_shared<Scene3D>();
    scene->init(args);
    scene->load(algo);
    return scene;
}
