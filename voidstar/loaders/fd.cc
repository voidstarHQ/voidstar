#include <string>

#include "voidstar/loaders/loader.h"
#include "voidstar/types.h"

class FdLoader final : public Loader {
 public:
  FdLoader(const std::string& UNUSED(fd)) : Loader(true) {}
  virtual ~FdLoader() {}

  static bool CanLoad(const std::string& uri) { return ("-" == uri); };

  virtual void load();
  virtual void free();

  virtual const u8* data() { throw std::runtime_error("TODO"); }
  virtual const u8* dataChunk(u32 UNUSED(offset), u32 UNUSED(size)) {
    throw std::runtime_error("TODO");
  }

 protected:
  int fd_;
};
REGISTER_LOADER(FdLoader)

void FdLoader::load() { throw std::runtime_error("TODO"); }

void FdLoader::free() { throw std::runtime_error("TODO"); }
