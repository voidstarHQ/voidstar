#include <fstream>

#include "voidstar/loaders/loader.h"
#include "voidstar/loaders/uri.h"
#include "voidstar/types.h"

class FileLoader final : public Loader {
 public:
  FileLoader(const std::string& path) : Loader(false), path_(path) {}
  virtual ~FileLoader() {}

  static bool CanLoad(const std::string& uri) {
    return ("file" == Uri<>::parse(uri).protocol);
  };

  virtual void load() ;
  virtual void free() ;

  virtual const u8* data()  {
    return reinterpret_cast<const u8*>(data_.data());
  }
  virtual const u8* dataChunk(u32 offset, u32 size __unused)  {
    return data() + offset;
  }

 protected:
  std::string path_;
  std::ifstream is_;
  std::string data_;
};
REGISTER_LOADER(FileLoader)

void FileLoader::load() {
  is_.open(path_, std::ios::in | std::ios::binary);
  if (!is_.good()) throw std::invalid_argument("Failed to open file");

  auto fsize = is_.tellg();
  if (fsize == -1) throw std::invalid_argument("Cannot read file");
  if (fsize > std::numeric_limits<u32>::max())
    size_ = std::numeric_limits<u32>::max();
  else
    size_ = static_cast<u32>(fsize);

  data_.reserve(size_);
  is_.seekg(0);
  is_.read(&data_[0], size_);
}

void FileLoader::free() {
  data_.reserve(0);
  is_.close();
  size_ = 0;
}
