#pragma once

#include "voidstar/algorithm.h"

class Algo3D : public Algorithm {
 public:
  virtual ~Algo3D() {}

  static constexpr char kSceneType[] = "Scene3D";
  virtual std::string sceneType() const final { return kSceneType; }

  virtual bool apply(Floats& vertices, Floats& colors, VertIndices& selected,
                     u32 width, u32 height, u32 depth) = 0;
};
