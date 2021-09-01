#include "voidstar/algorithm.h"

#include <iostream>

#include "voidstar/size2str.h"

REGISTRY_IMPLEMENTATION_FOR(Algorithm)
REGISTER_META("algorithms", Algorithm)

size_t Size(const Floats& v) { return sizeof(GLfloat) * v.size(); }
size_t Size(const VertIndices& v) { return sizeof(Index) * v.size(); }

void Algorithm::use(std::shared_ptr<Loader> loader,
                    std::shared_ptr<DataRange> range) {
  // TODO: delete loader prior to creating a new one (same for range)
  if (loader_ && loader != loader_) std::cerr << "deleting loader" << std::endl;
  loader_ = loader;
  if (loader_->size() < min_data_size_)
    throw std::range_error("this algorithm needs more data");
  if (range_ && range_ != range) std::cerr << "deleting range" << std::endl;
  range_ = range;
  if (!range_) {
    range_ = std::make_shared<DataRange>(0, loader_->size());
  }
}

const u8* Algorithm::loadDataRange(const DataRange& range, u32& size) {
  if (max_data_size_)
    size = std::min<u32>(range.size(), max_data_size_);
  else
    size = range.size();
  std::cerr << "read " << size2str(size) << " bytes" << std::endl;
  return loader_->dataChunk(range.begin, size);
}
