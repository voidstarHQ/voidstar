#include <iostream>
#include <functional>
#include <string>
#include <map>

#include <Arguments.hh>
#include <Algorithm.hh>
#include <FileLoader.hh>
#include <Manager.hh>
#include <Scene.hh>

int main(int argc, char *argv[])
{
    auto *args = parseArgs(argc, argv);
    if (!args) {
        return 0;
    }

    Loader *loader;
    if (args->input.empty()) {
        loader = new NullLoader();
    } else if (args->input == "-") {
        loader = new FileLoader(0);
    } else {
        loader = new FileLoader(args->input);
    }
    loader->load();

    //auto *algorithm = algorithms[args->algo]();
    //algorithm->use(loader);

    auto *manager = managers[args->manager](args);
    try {
        manager->init();
        auto scene = new Scene(manager);
        scene->init();
        //scene->load(algorithm);
        manager->loadScene(scene);
        manager->run();
    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
