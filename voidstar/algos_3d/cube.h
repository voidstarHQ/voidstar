#pragma once

#include "voidstar/algos_3d/algo_3d.h"

class Algo3DCube : public Algo3D {
 public:
  virtual ~Algo3DCube() {}

  virtual bool apply(Floats& vertices, Floats& colors, VertIndices& selected,
                     u32 width, u32 height, u32 depth) = 0;

 protected:
  u32 make_vertices(Floats& vertices, u32 width, u32 height, u32 depth) {
    const float w = static_cast<float>(width) / 2;
    const float h = static_cast<float>(height) / 2;
    const float d = static_cast<float>(depth) / 2;

    size_t pos = 0;
    for (u32 z = 0; z < depth; ++z)
      for (u32 y = 0; y < height; ++y)
        for (u32 x = 0; x < width; ++x) {
          vertices[pos++] = (static_cast<float>(x) - w) / w;
          vertices[pos++] = (static_cast<float>(y) - h) / h;
          vertices[pos++] = (static_cast<float>(z) - d) / d;
        }

    return static_cast<u32>(vertices.size()) / 3;
  }
};
