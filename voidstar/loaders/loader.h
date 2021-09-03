#pragma once

#include <memory>

#include "voidstar/registrar.h"
#include "voidstar/types.h"

class Loader {
 public:
  Loader(bool stream) : stream_(stream), size_(0), offset_(0) {}
  virtual ~Loader() {}

  virtual void load() = 0;
  virtual void free() = 0;

  virtual const u8* data() = 0;
  virtual const u8* dataChunk(u32 offset, u32 size) = 0;
  virtual const u8* nextDataChunk(u32 size) {
    auto chunk = dataChunk(offset_, size);
    offset_ += size;
    return chunk;
  }

  static std::shared_ptr<Loader> fromURI(const std::string& uri);

  void offset(u32 offset) { offset_ = offset; }
  u32 offset() const { return offset_; }
  u32 size() const { return size_; }
  bool isStream() { return stream_; }

 protected:
  bool stream_;
  u32 size_;
  u32 offset_;
};

REGISTRY_DECLARATION_FOR(
    Loader, std::function<std::shared_ptr<Loader>()>(const std::string&));
#define REGISTER_LOADER(KLASS)                                            \
  REGISTRY_REGISTER_FOR(                                                  \
      Loader, #KLASS, KLASS,                                              \
      (const std::string& uri)->std::function<std::shared_ptr<KLASS>()> { \
        if (KLASS::CanLoad(uri))                                          \
          return [&]() -> std::shared_ptr<KLASS> {                        \
            return std::make_shared<KLASS>(uri);                          \
          };                                                              \
        return nullptr;                                                   \
      })
