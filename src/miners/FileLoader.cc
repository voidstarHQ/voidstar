#include <fstream>

#include <FileLoader.hh>

void FileLoader::load()
{
    if ( fd_ != -1 ) {
        throw std::runtime_error("Unsupported fd usage");
    } else {
        is_.open( path_, std::ios::in | std::ios::binary );
        if (!is_.good()) {
            throw std::invalid_argument("Failed to open file");
        }
    }

   auto size = is_.tellg();
   data_.reserve(size);
   is_.seekg(0);
   is_.read(&data_[0], size);
}

void FileLoader::free()
{
    data_.reserve(0);
    is_.close();
}

const std::string& FileLoader::dataAll()
{
    return data_;
}

const std::string& FileLoader::dataChunk(size_t size __unused)
{
    throw std::runtime_error("Unsupported operation");
}

