#include <unistd.h>
#include <string>

#include <FdLoader.hh>

std::shared_ptr<FdLoader>
FdLoader::make(const std::string& uri) {
    if ("-" == uri)
        return std::make_shared<FdLoader>(STDIN_FILENO);
    return nullptr;
}

void
FdLoader::load() {
    throw std::runtime_error("TODO");
}

void
FdLoader::free() {
    throw std::runtime_error("TODO");
}

const u8*
FdLoader::data() {
    throw std::runtime_error("TODO");
}

const u8*
FdLoader::dataChunk(size_t offset __unused, size_t size __unused) {
    throw std::runtime_error("TODO");
}
