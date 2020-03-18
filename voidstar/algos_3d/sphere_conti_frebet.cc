#include "voidstar/algos_3d/sphere.h"

class Algo3DSphereContiFrebet : public Algo3DSphere {
 public:
  Algo3DSphereContiFrebet() {}
  virtual ~Algo3DSphereContiFrebet() {}

  virtual bool apply(Floats& vertices, Floats& colors, VertIndices& indices,
                     size_t width, size_t height, size_t depth) final {
    make_vertices(vertices, width, height, depth);

    size_t size;
    const u8* data = loadDataRange(size);
    u8 x = data[0];
    u8 y = data[1];

    for (size_t i = 2; i + 3 < size; ++i) {
      u8 z = data[i];
      Index id = x + y * height + z * depth * height;
      // float r = std::sqrt(std::pow(static_cast<float>(x), 2.0f) +
      //                     std::pow(static_cast<float>(y), 2.0f) +
      //                     std::pow(static_cast<float>(z), 2.0f));
      // float theta = std::acos(static_cast<float>(z) / r);
      // float phi   = std::atan(static_cast<float>(y) / static_cast<float>(x));
      // size_t id = r + theta * height + phi * depth * height;
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
REGISTER_ALGORITHM("sphere_frebet", Algo3DSphereContiFrebet);
