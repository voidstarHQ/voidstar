#include "voidstar/algos_2d/algo_2d.h"

class Algo2DGrayscale : public Algo2D {
 public:
  Algo2DGrayscale() {}
  virtual ~Algo2DGrayscale() final {}
  virtual bool apply(Floats& vertices, Floats& colors, u32 width,
                     u32 height) final {
    make_vertices(vertices, width, height);

    const u32 chunk_size = width * height;
    const u8* data = loader_->dataChunk(0, chunk_size);
    size_t pos = 0;
    for (u32 i = 0; i < chunk_size; ++i) {
      float c = static_cast<float>(data[i]) / 255;
      colors[pos++] = c;
      colors[pos++] = c;
      colors[pos++] = c;
    }

    return true;
  }
};
REGISTER_ALGORITHM(Algo2DGrayscale)
