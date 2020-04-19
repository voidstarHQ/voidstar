#include "voidstar/loaders/loader.h"

#include <iostream>

REGISTRY_IMPLEMENTATION_FOR(Loader);

std::shared_ptr<Loader> Loader::fromURI(const std::string& uri) {
  for (const auto& [name, loaderFactory] : RegistryForLoader()) {
    assert(loaderFactory);
    auto maybe_loader = loaderFactory(uri);
    if (maybe_loader) {
      std::cout << "Picked loader: " << name << std::endl
                << "Loading file: " << uri << std::endl;
      return maybe_loader();
    }
  }
  return nullptr;
}
