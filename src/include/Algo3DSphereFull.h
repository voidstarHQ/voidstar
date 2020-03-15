#pragma once

#include "src/include/Algo3DSphere.h"

class Algo3DSphereFull : public Algo3DSphere {
 public:
  Algo3DSphereFull() {}
  virtual ~Algo3DSphereFull() {}

  virtual bool apply(Floats& vertices, Floats& colors, VertIndices& selected,
                     size_t width, size_t height, size_t depth);
};
