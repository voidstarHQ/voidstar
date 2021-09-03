#pragma once

#include "voidstar/algorithm.h"

class Algo2D : public Algorithm {
 public:
  virtual ~Algo2D() {}

  static constexpr char kSceneType[] = "Scene2D";
  virtual std::string sceneType() const final { return kSceneType; }

  virtual bool apply(Floats& vertices, Floats& colors, u32 width,
                     u32 height) = 0;

 protected:
  u32 make_vertices(Floats& vertices, u32 width, u32 height) {
    const float w = static_cast<float>(width) / 2;
    const float h = static_cast<float>(height) / 2;

    size_t pos = 0;
    for (u32 y = 0; y < height; ++y)
      for (u32 x = 0; x < width; ++x) {
        vertices[pos++] = (static_cast<float>(x) - w) / w;
        vertices[pos++] = (static_cast<float>(y) - h) / h;
      }
    return static_cast<u32>(vertices.size()) / 2;
  }
};
