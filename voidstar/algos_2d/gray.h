#pragma once

#include "src/include/Algo2D.h"

class Algo2DGrayscale : public Algo2D {
 public:
  Algo2DGrayscale() {}
  virtual ~Algo2DGrayscale() {}

  virtual bool apply(Floats& vertices, Floats& colors, size_t width,
                     size_t height);
};
