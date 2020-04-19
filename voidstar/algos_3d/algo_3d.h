#pragma once

#include "voidstar/algorithm.h"

class Algo3D : public Algorithm {
 public:
  virtual ~Algo3D() {}

  static constexpr char kSceneType[] = "Scene3D";
  virtual std::string sceneType() const final { return kSceneType; }

  virtual bool apply(Floats& vertices, Floats& colors, VertIndices& selected,
                     size_t width, size_t height, size_t depth) = 0;
};
