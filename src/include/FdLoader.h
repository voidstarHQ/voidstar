#pragma once

#include "src/include/Loader.h"
#include "src/include/Types.h"

class FdLoader : public Loader {
 public:
  FdLoader(int fd) : Loader(true), fd_(fd) {}
  virtual ~FdLoader() {}

  static std::shared_ptr<FdLoader> make(const std::string& uri);
  virtual void load();
  virtual void free();

  virtual const u8* data();
  virtual const u8* dataChunk(size_t pos, size_t size);

 protected:
  int fd_;
};
