#include <Algorithm2DGrayscale.hh>

struct GrayscaleRGBColor {
    float r, g, b;
    float c2c(u8 c) { return (float)c / 255.0f; }
    GrayscaleRGBColor(u8 byte) {
        auto c = c2c(byte);
        r = g = b = c;
    }
};


bool
Algorithm2DGrayscale::apply(GLfloat* vertices, GLfloat* colors,
                            size_t width, size_t height) {
    size_t pos_v = 0;
    for (size_t y = 0; y < height; ++y)
        for (size_t x = 0; x < width; ++x) {
            vertices[pos_v++] = ((float)x - (float)width  / 2.0f) / 128;
            vertices[pos_v++] = ((float)y - (float)height / 2.0f) / 128;
        }

    const size_t chunk_size = width * height;
    const u8* read = loader_->dataChunk(0, chunk_size);
    size_t pos_c = 0;
    for (size_t i = 0; i < chunk_size; ++i) {
        auto c = GrayscaleRGBColor(read[i]);
        colors[pos_c++] = c.r;
        colors[pos_c++] = c.g;
        colors[pos_c++] = c.b;
        colors[pos_c++] = 1.0f;
    }

    return true;
}
