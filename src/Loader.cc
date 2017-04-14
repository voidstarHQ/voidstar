#include <vector>
#include <functional>
#include <iostream>

#include <Uri.hh>
#include <Loader.hh>
#include <FileLoader.hh>
#include <MmapLoader.hh>

using LoaderFactoryFunc = std::function<Loader*(const std::string&)>;

#define LOADER(Body) [](std::string uri) -> Loader* { Body }
std::vector<std::pair<std::string, LoaderFactoryFunc>> loaders = {
    { "file", LOADER( return new FileLoader(uri); ) },
    { "", LOADER(
        if (uri == "-") return new FileLoader(0);
        else return new MmapFileLoader(uri);
    ) },
};

Loader *loaderFromUri(const std::string& uri)
{
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

