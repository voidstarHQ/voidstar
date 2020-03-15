#pragma once

#include "src/include/Algo2D.h"

class Algo2DFourColors : public Algo2D {
 public:
  Algo2DFourColors() {}
  virtual ~Algo2DFourColors() {}

  virtual bool apply(Floats& vertices, Floats& colors, size_t width,
                     size_t height);
};
