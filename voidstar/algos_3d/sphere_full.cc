#include "voidstar/algos_3d/sphere.h"

class Algo3DSphereFull : public Algo3DSphere {
 public:
  Algo3DSphereFull() {}
  virtual ~Algo3DSphereFull() {}

  virtual bool apply(Floats& vertices, Floats& colors, VertIndices& selected,
                     size_t width, size_t height, size_t depth) final {
    auto nb_verts = make_vertices(vertices, width, height, depth);

    for (size_t i = 0; i < nb_verts; ++i) {
      colors[3 * i + 0] = 1.0f;
      colors[3 * i + 1] = 1.0f;
      colors[3 * i + 2] = 1.0f;
      selected.push_back(i);
    }

    return true;
  }
};
REGISTER_ALGORITHM("sphere", Algo3DSphereFull);
