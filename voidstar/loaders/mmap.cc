#include <fcntl.h>

#ifndef _WIN32
#include <unistd.h>
#endif

#include <filesystem>

#ifdef _WIN32
#include "mman.h"
#else
#include <sys/mman.h>
#endif

#include "voidstar/loaders/loader.h"
#include "voidstar/loaders/uri.h"

class MmapLoader final : public Loader {
 public:
  MmapLoader(int fd) : Loader(true), fd_(fd) {}
  MmapLoader(const std::string& path) : Loader(false), path_(path) {}
  virtual ~MmapLoader() {
    if (data_) free();
  }

  static bool CanLoad(const std::string& uri) {
    if (Uri<>::parse(uri).protocol.empty())
      return !std::filesystem::is_directory(uri);
    return false;
  };

  virtual void load();
  virtual void free();

  virtual const u8* data() { return data_; }
  virtual const u8* dataChunk(u32 offset, u32 size) {
    if (size_ < offset + size)
      throw std::out_of_range("Trying to read data out of bound");
    return data() + offset;
  }

 protected:
  int fd_ = -1;
  u8* data_ = nullptr;
  std::string path_;

  void close_fd() {
#ifndef _WIN32  // TODO: close FDs on windows
    if (fd_ >= 0) close(fd_);
#endif
    fd_ = -1;
  }
};
REGISTER_LOADER(MmapLoader)

void MmapLoader::load() {
  std::error_code ec;
  auto filesize = std::filesystem::file_size(path_, ec);
  if (ec) throw std::invalid_argument(ec.message());
  if (filesize > std::numeric_limits<u32>::max())
    size_ = std::numeric_limits<u32>::max();
  else
    size_ = static_cast<u32>(filesize);

  if (fd_ < 0) {
    fd_ = open(path_.c_str(), O_RDONLY);
    if (fd_ < 0) throw std::runtime_error("Impossible to read file");
  }

  auto base = mmap(0, size_, PROT_READ, MAP_PRIVATE, fd_, 0);
  if (nullptr == base) {
    close_fd();
    throw std::runtime_error("Failed to map data");
  }
  data_ = reinterpret_cast<u8*>(base);
}

void MmapLoader::free() {
  munmap(data_, size_);
  close_fd();
  data_ = nullptr;
  offset_ = 0;
  size_ = 0;
}
