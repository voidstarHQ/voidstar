#include <Algo2DGrayscale.hh>

struct GrayscaleRGBColor {
    float r, g, b;
    float c2c(u8 c) { return (float)c / 255.0f; }
    GrayscaleRGBColor(u8 byte) {
        auto c = c2c(byte);
        r = g = b = c;
    }
};


bool
Algo2DGrayscale::apply(GLfloat* vertices, GLfloat* colors,
                       size_t width, size_t height) {
    make_vertices(vertices, width, height);

    const size_t chunk_size = width * height;
    const u8* read = loader_->dataChunk(0, chunk_size);
    size_t pos = 0;
    for (size_t i = 0; i < chunk_size; ++i) {
        auto c = GrayscaleRGBColor(read[i]);
        colors[pos++] = c.r;
        colors[pos++] = c.g;
        colors[pos++] = c.b;
        colors[pos++] = 1.0f;
    }

    return true;
}
