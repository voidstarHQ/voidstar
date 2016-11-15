#include <fstream>

#include <FileLoader.hh>

void
FileLoader::load()
{
    if (fd_ != -1)
        throw std::runtime_error("Unsupported fd usage");
    is_.open(path_, std::ios::in | std::ios::binary);
    if (!is_.good())
        throw std::invalid_argument("Failed to open file");

   size_ = is_.tellg();
   data_.reserve(size_);
   is_.seekg(0);
   is_.read(&data_[0], size_);
}

void
FileLoader::free()
{
    data_.reserve(0);
    is_.close();
    size_ = 0;
}

const u8*
FileLoader::data()
{
    return reinterpret_cast<const u8*>(data_.data());
}

const u8*
FileLoader::dataChunk(size_t offset, size_t size __unused)
{
    return data() + offset;
}
