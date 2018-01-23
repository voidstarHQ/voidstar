#include <FdFileLoader.hh>

std::shared_ptr<FdFileLoader>
FdFileLoader::make(const std::string& uri) {
    if ("-" == uri)
        return std::make_shared<FdFileLoader>(STDIN_FILENO);
    return NULL;
}

void
FdFileLoader::load() {
    throw std::runtime_error("TODO");
}

void
FdFileLoader::free() {
    throw std::runtime_error("TODO");
}

const u8*
FdFileLoader::data() {
    throw std::runtime_error("TODO");
}

const u8*
FdFileLoader::dataChunk(size_t offset __unused, size_t size __unused) {
    throw std::runtime_error("TODO");
}
