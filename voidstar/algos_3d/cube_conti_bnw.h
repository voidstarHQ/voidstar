#pragma once

#include "src/include/Algo3DCube.h"

class Algo3DCubeContiBnW : public Algo3DCube {
 public:
  Algo3DCubeContiBnW() {}
  virtual ~Algo3DCubeContiBnW() {}

  virtual bool apply(Floats& vertices, Floats& colors, VertIndices& selected,
                     size_t width, size_t height, size_t depth);
};
