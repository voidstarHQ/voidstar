#include <fstream>

#include "voidstar/loaders/loader.h"
#include "voidstar/loaders/uri.h"
#include "voidstar/types.h"

class FileLoader : public Loader {
 public:
  FileLoader(const std::string& path) : Loader(false), path_(path) {}
  virtual ~FileLoader() {}

  static bool CanLoad(const std::string& uri) {
    return ("file" == Uri<>::parse(uri).protocol);
  };

  virtual void load() final;
  virtual void free() final;

  virtual const u8* data() final {
    return reinterpret_cast<const u8*>(data_.data());
  }
  virtual const u8* dataChunk(u32 offset, u32 size __unused) final {
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

  size_ = is_.tellg();
  data_.reserve(size_);
  is_.seekg(0);
  is_.read(&data_[0], size_);
}

void FileLoader::free() {
  data_.reserve(0);
  is_.close();
  size_ = 0;
}
