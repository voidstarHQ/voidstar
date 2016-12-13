#include <iostream>
#include <Algo3DCubeContiRainbow.hh>

bool
Algo3DCubeContiRainbow::apply(GLfloat* vertices, GLfloat* colors, VertIndices& selected,
                              size_t width, size_t height, size_t depth) {
    size_t pos = 0;
    for (size_t z = 0; z < depth; ++z)
        for (size_t y = 0; y < height; ++y)
            for (size_t x = 0; x < width; ++x) {
                vertices[pos++] = ((float)x - (float)width  / 2.0f) / 128;
                vertices[pos++] = ((float)y - (float)height / 2.0f) / 128;
                vertices[pos++] = ((float)z - (float)depth  / 2.0f) / 128;
            }

    const size_t chunk_size = 1024 * 100;
    const u8* read = loader_->dataChunk(0, chunk_size);
    std::cerr << "read " << chunk_size << " bytes!" << std::endl;
    u8 x = read[0];
    u8 y = read[1];

    for (size_t i = 2; i < chunk_size; ++i) {
        u8 z = read[i];
        size_t id = x + y * height + z * depth * height;
        size_t idx = 4 * id;
        colors[idx + 0] = static_cast<float>(x) / 255.0f;
        colors[idx + 1] = static_cast<float>(y) / 255.0f;
        colors[idx + 2] = static_cast<float>(z) / 255.0f;
        float opacity = colors[idx + 3];
        if (opacity < 1.0f/255.0f)
            selected.push_back(id);
        // colors[idx + 3] = std::min(1.0f, 1.0f/255.0f + opacity);
        colors[idx + 3] = 1.0f;
        x = y;
        y = z;
    }

    return true;
}
