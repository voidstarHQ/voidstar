#include <cstring>

#include <FdLoader.hh>

std::shared_ptr<FdLoader>
FdLoader::make(const std::string& uri) {
    if (!strncmp("-", uri.c_str(), 1))
        return std::make_shared<FdLoader>(STDIN_FILENO);
    return NULL;
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
