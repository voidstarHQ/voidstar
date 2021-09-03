#include "voidstar/algos_3d/cube.h"

class Algo3DCubeContiBnW final : public Algo3DCube {
 public:
  Algo3DCubeContiBnW() {}
  virtual ~Algo3DCubeContiBnW() {}

  virtual bool apply(Floats& vertices, Floats& colors, VertIndices& indices,
                     u32 width, u32 height, u32 depth)  {
    make_vertices(vertices, width, height, depth);

    u32 size;
    const u8* data = loadDataRange(size);
    u8 x = data[0];
    u8 y = data[1];

    for (u32 i = 2; i < size; ++i) {
      u8 z = data[i];
      Index id = (y * width + x) * depth + z;
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
REGISTER_ALGORITHM(Algo3DCubeContiBnW)
