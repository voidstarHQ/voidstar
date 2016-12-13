#include <iostream>
#include <Algo3DCubeContiFrebet.hh>

bool
Algo3DCubeContiFrebet::apply(GLfloat* vertices, GLfloat* colors, VertIndices& selected,
                             size_t width, size_t height, size_t depth) {
    make_vertices(vertices, width, height, depth);

    const size_t chunk_size = 1024 * 100;
    const u8* read = loader_->dataChunk(0, chunk_size);
    std::cerr << "read " << chunk_size << " bytes!" << std::endl;
    u8 x = read[0];
    u8 y = read[1];

    for (size_t i = 2; i < chunk_size; ++i) {
        u8 z = read[i];
        size_t id = x + y * height + z * depth * height;
        size_t idx = 4 * id;
        colors[idx + 0] = static_cast<float>(read[i+1]) / 255.0f;
        colors[idx + 1] = static_cast<float>(read[i+2]) / 255.0f;
        colors[idx + 2] = static_cast<float>(read[i+3]) / 255.0f;
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
