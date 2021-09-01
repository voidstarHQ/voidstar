#pragma once

#include <memory>

#include "voidstar/arguments.h"
#include "voidstar/data_range.h"
#include "voidstar/indices.h"
#include "voidstar/loaders/loader.h"
#include "voidstar/registrar.h"

size_t Size(const Floats& v);
size_t Size(const VertIndices& v);

class Algorithm {
 public:
  Algorithm(u32 min_size = 0, u32 max_size = 0)
      : min_data_size_(min_size),
        max_data_size_(max_size),
        loader_(0),
        range_(0) {}
  virtual ~Algorithm() {}

  virtual std::string sceneType() const = 0;
  virtual void use(std::shared_ptr<Loader> loader,
                   std::shared_ptr<DataRange> range = NULL);

  const u8* loadDataRange(const DataRange& range, u32& size);

  inline const u8* loadDataRange(u32& size) {
    return loadDataRange(*range_, size);
  }
  inline std::shared_ptr<DataRange> range() { return range_; }
  inline std::shared_ptr<Loader> loader() { return loader_; }

 protected:
  u32 min_data_size_;
  u32 max_data_size_;
  std::shared_ptr<Loader> loader_;
  std::shared_ptr<DataRange> range_;
};

REGISTRY_DECLARATION_FOR(Algorithm, std::shared_ptr<Algorithm>());
#define REGISTER_ALGORITHM(KLASS) \
  REGISTRY_REGISTER_FOR(          \
      Algorithm, #KLASS, KLASS, () { return std::make_shared<KLASS>(); })
