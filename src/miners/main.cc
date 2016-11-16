#include <iostream>
#include <functional>
#include <string>
#include <map>

#include <Arguments.hh>
#include <Algorithm.hh>
#include <FileLoader.hh>
#include <MmapLoader.hh>
#include <Manager.hh>
#include <Scene.hh>
#include <Scene2D.hh>
#include <Scene3D.hh>

int
main(int argc, char* argv[])
{
    auto* args = parseArgs(argc, argv);
    if (!args) {
        return 0;
    }

    Loader* loader = NULL;
    if (args->input.empty()) {
        loader = new NullLoader();
    } else if (args->input == "-") {
        loader = new FileLoader(0);
    } else {
        loader = new MmapFileLoader(args->input);
    }
    loader->load();

    auto* algorithm = algorithms[args->algo]();
    algorithm->use(loader);

    auto* manager = managers[args->manager](args);
    try {
        manager->init();
        if (args->scene == "3d") {
            auto* scene = new Scene3D(manager);
            scene->init();
            scene->load(reinterpret_cast<Algorithm3D*>(algorithm));
            manager->loadScene(reinterpret_cast<Scene*>(scene));
            manager->run();
        } else if (args->scene == "2d") {
            auto* scene = new Scene2D(manager);
            scene->init();
            scene->load(reinterpret_cast<Algorithm2D*>(algorithm));
            manager->loadScene(reinterpret_cast<Scene*>(scene));
            manager->run();
        }
    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
