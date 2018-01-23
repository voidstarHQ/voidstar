#include <vector>
#include <functional>
#include <iostream>

#include <Loader.hh>
#include <FileLoader.hh>
#include <FdFileLoader.hh>
#include <MmapFileLoader.hh>

using SomeLoader = std::shared_ptr<Loader>;
using SomeLoaderFactoryFunc = std::function<SomeLoader(const std::string&)>;

#define LOADER(Kind) [](std::string uri) -> SomeLoader { return Kind::make(uri); }

SomeLoader
loaderFromUri(const std::string& uri) {
    static const std::vector<SomeLoaderFactoryFunc> loaders = {
        {LOADER(FdFileLoader),
         LOADER(FileLoader),
         LOADER(MmapFileLoader)
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
