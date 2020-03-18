#include <unistd.h>

#include <string>

#include "voidstar/loaders/loader.h"
#include "voidstar/types.h"

class FdLoader : public Loader {
 public:
  FdLoader(const std::string& fd) : Loader(true) {
    if (fd == "-") fd_ = STDIN_FILENO;
  }
  virtual ~FdLoader() {}

  static bool CanLoad(const std::string& uri) { return ("-" == uri); };

  virtual void load() final;
  virtual void free() final;

  virtual const u8* data() final { throw std::runtime_error("TODO"); }
  virtual const u8* dataChunk(size_t offset __unused,
                              size_t size __unused) final {
    throw std::runtime_error("TODO");
  }

 protected:
  int fd_;
};
REGISTER_LOADER("fd", FdLoader);

void FdLoader::load() { throw std::runtime_error("TODO"); }

void FdLoader::free() { throw std::runtime_error("TODO"); }
