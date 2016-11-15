#include <Algorithm2DFourColors.hh>

struct RGBColor {
    float r, g, b;
    float c2c(unsigned char c) { return (float)c / 255.0f; }
    RGBColor(unsigned char byte) {
        if (0x00 == byte) {
            r = 1.0f; g = 1.0f; b = 1.0f;
            return;
        }
        if (0xff == byte) {
            r = 0.0f; g = 0.0f; b = 0.0f;
            return;
        }
        if (0x20 <= byte && byte <= 0x7e) {
            r = c2c(0x37); g = c2c(0x7e); b = c2c(0xb8);
            return;
        }
        r = c2c(0xe4); g = c2c(0x1a); b = c2c(0x1c);
    }
};


bool
Algorithm2DFourColors::apply(GLfloat* vertices, GLfloat* colors,
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
        auto c = RGBColor(read[i]);
        colors[pos_c++] = c.r;
        colors[pos_c++] = c.g;
        colors[pos_c++] = c.b;
        colors[pos_c++] = 1.0f;
    }

    return true;
}
