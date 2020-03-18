#include "voidstar/algos_3d/sphere.h"

class Algo3DSphereContiBnW : public Algo3DSphere {
 public:
  Algo3DSphereContiBnW() {}
  virtual ~Algo3DSphereContiBnW() {}

  virtual bool apply(Floats& vertices, Floats& colors, VertIndices& indices,
                     size_t width, size_t height, size_t depth) final {
    make_vertices(vertices, width, height, depth);

    size_t size;
    const u8* data = loadDataRange(size);
    u8 x = data[0];
    u8 y = data[1];

    for (size_t i = 2; i < size; ++i) {
      u8 z = data[i];
      Index id = x + y * height + z * depth * height;
      Index idx = 3 * id;
      colors[idx + 0] = 1.0f;
      colors[idx + 1] = 1.0f;
      colors[idx + 2] = 1.0f;
      indices.push_back(id);
      x = y;
      y = z;
    }

    return true;
  }
};
REGISTER_ALGORITHM("sphere_bnw", Algo3DSphereContiBnW);
