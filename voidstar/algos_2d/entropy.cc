#include <cmath>

#include "voidstar/algos_2d/algo_2d.h"

class Algo2DEntropy : public Algo2D {
 public:
  Algo2DEntropy() {}
  virtual ~Algo2DEntropy() {}

  virtual bool apply(Floats& vertices, Floats& colors, u32 width,
                     u32 height) final {
    make_vertices(vertices, width, height);

    const u32 chunk_size = width * height;
    const u8* data = loader_->dataChunk(0, chunk_size);
    size_t pos = 0;
    for (u32 i = 0; i < chunk_size; ++i) {
      const float e = entropy(data, chunk_size, i, 32, 256);
      const float r = (e > 0.5f) ? curve(e - 0.5f) : 0.0f;
      const float b = std::pow(e, 2.f);
      colors[pos++] = r;
      colors[pos++] = 0.0f;
      colors[pos++] = b;
    }

    return true;
  }

 private:
  // github.com/cortesi/scurve/blob/a59e8335c48a7cda7043fbd1b28bcae1abc9645d/binvis#L58

  inline float entropy(const u8* data, u32 len, u32 offset,
                       size_t blocksize = 32, size_t n_symbols = 256) {
    if (len < blocksize)
      throw std::range_error("Data length must be larger than block size.");

    size_t start;
    const auto half_block = blocksize / 2;
    if (offset < half_block)
      start = 0;
    else if (offset > len - half_block)
      start = len - half_block;
    else
      start = offset - half_block;

    std::vector<float> hist(n_symbols, 0.0f);
    for (auto i = start; i < start + blocksize; ++i) hist[data[i]]++;

    auto Blocksize = static_cast<float>(blocksize);
    auto base = static_cast<float>(std::min(blocksize, n_symbols));
    auto base_log = 1 / std::log(base);
    float entropy = 0;
    for (float value : hist) {
      if (value < 1.0f) continue;
      float p = value / Blocksize;
      // If blocksize < 256, the number of possible byte values is restricted.
      // In that case, we adjust the log base to make sure we get a value
      // between 0 and 1.
      entropy += p * std::log(p) * base_log;
    }
    return -entropy;
  }

  inline float curve(float v) {
    float f = std::pow(4.f * (v - std::pow(v, 2.f)), 4.f);
    return std::max(f, 0.0f);
  }
};
REGISTER_ALGORITHM(Algo2DEntropy)
