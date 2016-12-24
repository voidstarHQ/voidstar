#include <Algo2DFourColors.hh>

struct RGBColor {
    float r, g, b;
    float c2c(u8 c) { return (float)c / 255.0f; }
    RGBColor(u8 byte) {
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
Algo2DFourColors::apply(GLfloat* vertices, GLfloat* colors,
                        size_t width, size_t height) {
    make_vertices(vertices, width, height);

    const size_t chunk_size = width * height;
    const u8* read = loader_->dataChunk(0, chunk_size);
    size_t pos = 0;
    for (size_t i = 0; i < chunk_size; ++i) {
        auto c = RGBColor(read[i]);
        colors[pos++] = c.r;
        colors[pos++] = c.g;
        colors[pos++] = c.b;
        colors[pos++] = 1.0f;
    }

    return true;
}
