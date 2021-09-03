#include "voidstar/algos_3d/cube.h"

class Algo3DCubeFull final : public Algo3DCube {
 public:
  Algo3DCubeFull() {}
  virtual ~Algo3DCubeFull() {}

  virtual bool apply(Floats& vertices, Floats& colors, VertIndices& selected,
                     u32 width, u32 height, u32 depth) {
    auto nb_verts = make_vertices(vertices, width, height, depth);

    for (u32 i = 0; i < nb_verts; ++i) {
      colors[3 * i + 0] = 1.0f;
      colors[3 * i + 1] = 1.0f;
      colors[3 * i + 2] = 1.0f;
      selected.push_back(i);
    }

    return true;
  }
};
REGISTER_ALGORITHM(Algo3DCubeFull)
