#include "src/include/Algo2DFourColors.h"

struct RGBColor {
    float r, g, b;
    inline float c2c(u8 c) { return static_cast<float>(c) / 255; }
    inline bool is_printable(u8 byte) {
        return (0x09 <= byte && byte <= 0x0d)
            || (0x20 <= byte && byte <= 0x7e);
    }
    RGBColor(u8 byte) {
        if (0x00 == byte) {
            r = 0; g = 0; b = 0;
        }
        else if (0xff == byte) {
            r = 1; g = 1; b = 1;
        }
        else if (is_printable(byte)) {
            r = c2c(55); g = c2c(126); b = c2c(184);
        }
        else {
            r = c2c(228); g = c2c(26); b = c2c(28);
        }
    }
};


bool
Algo2DFourColors::apply(Floats& vertices, Floats& colors,
                        size_t width, size_t height) {
    make_vertices(vertices, width, height);

    const size_t chunk_size = width * height;
    const u8* data = loader_->dataChunk(0, chunk_size);
    size_t pos = 0;
    for (size_t i = 0; i < chunk_size; ++i) {
        auto c = RGBColor(data[i]);
        colors[pos++] = c.r;
        colors[pos++] = c.g;
        colors[pos++] = c.b;
    }

    return true;
}
