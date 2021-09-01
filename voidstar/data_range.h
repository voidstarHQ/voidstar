#pragma once

#include "voidstar/types.h"

struct DataRange {
  DataRange(u32 b, u32 e) : begin(b), end(e) {}
  u32 begin;
  u32 end;
  u32 size() const { return end - begin; }
  static std::shared_ptr<DataRange> create(u32 begin, u32 end) {
    if (begin == 0 && end == 0) return NULL;
    return std::make_shared<DataRange>(begin, end);
  }
};
