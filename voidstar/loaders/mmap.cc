#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

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
    struct stat info;
    if (Uri<>::parse(uri).protocol.empty())
      if (!stat(uri.c_str(), &info))
        if (~info.st_mode & S_IFDIR) return true;
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
};
REGISTER_LOADER(MmapLoader)

void MmapLoader::load() {
  if (fd_ < 0) {
    fd_ = open(path_.c_str(), O_RDONLY);
    if (fd_ < 0) throw std::runtime_error("Impossible to read file");
  }

  auto fdsize = lseek(fd_, 0, SEEK_END);
  if (fdsize == -1) throw std::invalid_argument("Cannot read file");
  if (fdsize > std::numeric_limits<u32>::max())
    size_ = std::numeric_limits<u32>::max();
  else
    size_ = static_cast<u32>(fdsize);
  lseek(fd_, 0, SEEK_SET);

  auto base = mmap(0, size_, PROT_READ, MAP_PRIVATE, fd_, 0);
  if (nullptr == base) {
    close(fd_);
    throw std::runtime_error("Failed to map data");
  }
  data_ = reinterpret_cast<u8*>(base);
}

void MmapLoader::free() {
  munmap(data_, size_);
  data_ = nullptr;
  offset_ = 0;
  size_ = 0;
  // fd?
  // close(fd_)
}
