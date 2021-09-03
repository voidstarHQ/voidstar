#include "voidstar/algos_3d/cube.h"

class Algo3DCubeContiFrebet final : public Algo3DCube {
 public:
  Algo3DCubeContiFrebet() {}
  virtual ~Algo3DCubeContiFrebet() {}

  virtual bool apply(Floats& vertices, Floats& colors, VertIndices& indices,
                     u32 width, u32 height, u32 depth)  {
    make_vertices(vertices, width, height, depth);

    u32 size;
    const u8* data = loadDataRange(size);
    u8 x = data[0];
    u8 y = data[1];

    for (u32 i = 2; i + 3 < size; ++i) {
      u8 z = data[i];
      Index id = (y * width + x) * depth + z;
      Index idx = 3 * id;

      colors[idx + 0] = static_cast<float>(data[i + 1]) / 255.0f;
      colors[idx + 1] = static_cast<float>(data[i + 2]) / 255.0f;
      colors[idx + 2] = static_cast<float>(data[i + 3]) / 255.0f;
      indices.push_back(id);

      x = y;
      y = z;
    }

    return true;
  }
};
REGISTER_ALGORITHM(Algo3DCubeContiFrebet)
