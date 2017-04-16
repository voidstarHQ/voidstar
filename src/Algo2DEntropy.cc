#include <cmath>
#include <vector>
#include <iostream>

#include <Algo2DEntropy.hh>

// github.com/cortesi/scurve/blob/a59e8335c48a7cda7043fbd1b28bcae1abc9645d/binvis#L58

inline float
entropy (const u8* data, size_t len, size_t offset, size_t blocksize=32, size_t n_symbols=256) {
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
    for (size_t i = start; i < start + blocksize; ++i)
        hist[ data[i] ]++;

    auto Blocksize = static_cast<float>(blocksize);
    auto base = static_cast<float>(std::min(blocksize, n_symbols));
    auto base_log = 1 / std::log(base);
    float entropy = 0;
    for (float value : hist) {
        if (value < 1.0f)
            continue;
        float p = value / Blocksize;
        // If blocksize < 256, the number of possible byte values is restricted.
        // In that case, we adjust the log base to make sure we get a value
        // between 0 and 1.
        entropy += p * std::log(p) * base_log;
    }
    return - entropy;
}

inline float
curve (float v) {
    float f = std::pow(4 * (v - std::pow(v, 2)), 4);
    return std::max(f, 0.0f);
}

bool
Algo2DEntropy::apply(std::shared_ptr<GLfloat> vertices, std::shared_ptr<GLfloat> colors,
                     size_t width, size_t height) {
    make_vertices(vertices, width, height);

    const size_t chunk_size = width * height;
    const u8* data = loader_->dataChunk(0, chunk_size);
    size_t pos = 0;
    for (size_t i = 0; i < chunk_size; ++i) {
        auto e = entropy(data, chunk_size, i, 32, 256);
        float r = (e > 0.5f) ? curve(e - 0.5f) : 0.0f;
        float b = std::pow(e, 2);
        colors[pos++] = r;
        colors[pos++] = 0.0f;
        colors[pos++] = b;
        colors[pos++] = 1.0f;
    }

    return true;
}
