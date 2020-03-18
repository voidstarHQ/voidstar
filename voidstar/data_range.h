#pragma once

#include "voidstar/types.h"

struct DataRange {
  DataRange(size_t b, size_t e) : begin(b), end(e) {}
  size_t begin;
  size_t end;
  size_t size() const { return end - begin; }
  static std::shared_ptr<DataRange> create(size_t begin, size_t end) {
    if (begin == 0 && end == 0) return NULL;
    return std::make_shared<DataRange>(begin, end);
  }
};
