#include <Algo3DSphereContiRainbow.hh>

bool
Algo3DSphereContiRainbow::apply(std::shared_ptr<GLfloat> vertices, std::shared_ptr<GLfloat> colors,
                                VertIndices& selected,
                                size_t width, size_t height, size_t depth) {
    make_vertices(vertices, width, height, depth);

    size_t size;
    const u8* data = loadDataRange(size);
    u8 x = data[0];
    u8 y = data[1];

    for (size_t i = 2; i < size; ++i) {
        u8 z = data[i];
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
