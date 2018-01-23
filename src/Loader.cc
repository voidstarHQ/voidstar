#include <vector>
#include <functional>
#include <iostream>

#include <Loader.hh>
#include <FileLoader.hh>
#include <FdLoader.hh>
#include <MmapLoader.hh>

using SomeLoader = std::shared_ptr<Loader>;
using SomeLoaderFactoryFunc = std::function<SomeLoader(const std::string&)>;

SomeLoader
Loader::fromURI(const std::string& uri) {
    static const std::vector<SomeLoaderFactoryFunc> loaders = {
        {FdLoader::make,
         FileLoader::make,
         MmapLoader::make
        }
    };

    for (const auto& loader : loaders) {
        auto maybe_loader = loader(uri);
        if (NULL != maybe_loader) {
            std::cout << "Loading file " << uri << std::endl;
            return maybe_loader;
        }
    }
     throw std::runtime_error("No loader for file " + uri);
}
