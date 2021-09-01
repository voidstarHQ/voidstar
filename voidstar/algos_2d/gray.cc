#include "voidstar/algos_2d/algo_2d.h"

class Algo2DGrayscale : public Algo2D {
 public:
  Algo2DGrayscale() {}
  virtual ~Algo2DGrayscale() final {}
  virtual bool apply(Floats& vertices, Floats& colors, size_t width,
                     size_t height) final {
    make_vertices(vertices, width, height);

    const size_t chunk_size = width * height;
    const u8* data = loader_->dataChunk(0, chunk_size);
    size_t pos = 0;
    for (size_t i = 0; i < chunk_size; ++i) {
      float c = static_cast<float>(data[i]) / 255;
      colors[pos++] = c;
      colors[pos++] = c;
      colors[pos++] = c;
    }

    return true;
  }
};
REGISTER_ALGORITHM(Algo2DGrayscale)
