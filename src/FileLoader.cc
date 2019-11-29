#include "src/include/FileLoader.h"
#include "src/include/Uri.h"

std::shared_ptr<FileLoader>
FileLoader::make(const std::string& uri) {
    if ("file" == Uri<>::parse(uri).protocol)
        return std::make_shared<FileLoader>(uri);
    return nullptr;
}

void
FileLoader::load() {
    is_.open(path_, std::ios::in | std::ios::binary);
    if (!is_.good())
        throw std::invalid_argument("Failed to open file");

    size_ = is_.tellg();
    data_.reserve(size_);
    is_.seekg(0);
    is_.read(&data_[0], size_);
}

void
FileLoader::free() {
    data_.reserve(0);
    is_.close();
    size_ = 0;
}

const u8*
FileLoader::data() {
    return reinterpret_cast<const u8*>(data_.data());
}

const u8*
FileLoader::dataChunk(size_t offset, size_t size __unused) {
    return data() + offset;
}
