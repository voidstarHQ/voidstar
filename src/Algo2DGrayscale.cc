#include <Algo2DGrayscale.hh>

bool
Algo2DGrayscale::apply(Floats& vertices, Floats& colors,
                       size_t width, size_t height) {
    make_vertices(vertices, width, height);

    const size_t chunk_size = width * height;
    const u8* data = loader_->dataChunk(0, chunk_size);
    size_t pos = 0;
    for (size_t i = 0; i < chunk_size; ++i) {
        float c = static_cast<float>(data[i]) / 255;
        colors[pos++] = c;
        colors[pos++] = c;
        colors[pos++] = c;
        colors[pos++] = 1;
    }

    return true;
}
