#include "voidstar/algos_3d/cube.h"

class Algo3DCubeContiRainbow : public Algo3DCube {
 public:
  Algo3DCubeContiRainbow() {}
  virtual ~Algo3DCubeContiRainbow() {}

  virtual bool apply(Floats& vertices, Floats& colors, VertIndices& indices,
                     size_t width, size_t height, size_t depth) final {
    make_vertices(vertices, width, height, depth);

    size_t size;
    const u8* data = loadDataRange(size);
    u8 x = data[0];
    u8 y = data[1];

    for (size_t i = 2; i < size; ++i) {
      u8 z = data[i];
      Index id = (y * width + x) * depth + z;
      Index idx = 3 * id;
      colors[idx + 0] = static_cast<float>(x) / 255.0f;
      colors[idx + 1] = static_cast<float>(y) / 255.0f;
      colors[idx + 2] = static_cast<float>(z) / 255.0f;
      indices.push_back(id);
      x = y;
      y = z;
    }

    return true;
  }
};
REGISTER_ALGORITHM(Algo3DCubeContiRainbow)
