#include <vector>
#include <functional>
#include <iostream>
#include <unistd.h>

#include <Uri.hh>
#include <Loader.hh>
#include <FileLoader.hh>
#include <MmapFileLoader.hh>

using LoaderFactoryFunc = std::function<std::shared_ptr<Loader>(const std::string&)>;

#define LOADER(Body) [](std::string uri) -> std::shared_ptr<Loader> { Body }
std::vector<std::pair<std::string, LoaderFactoryFunc>> loaders = {
    {"file", LOADER( return std::make_shared<FileLoader>(uri); )},
    {"", LOADER(
            if (uri == "-") return std::make_shared<FileLoader>(STDIN_FILENO);
            else return std::make_shared<MmapFileLoader>(uri);
    )},
};

std::shared_ptr<Loader>
loaderFromUri(const std::string& uri) {
    auto data = Uri<>::parse(uri);
    for (const auto& pair : loaders) {
        auto& scheme = pair.first;
        if (data.protocol == scheme) {
            std::cout << "Loading file " << uri << std::endl;
            return pair.second(uri);
        }
    }
    throw std::runtime_error("No loader for file " + uri);
}
