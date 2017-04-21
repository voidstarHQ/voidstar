#include <Algo3DCubeContiFrebet.hh>

bool
Algo3DCubeContiFrebet::apply(Floats& vertices, Floats& colors, VertIndices& indices,
                             size_t width, size_t height, size_t depth) {
    make_vertices(vertices, width, height, depth);

    size_t size;
    const u8* data = loadDataRange(size);
    u8 x = data[0];
    u8 y = data[1];

    for (size_t i = 2; i+3 < size; ++i) {
        u8 z = data[i];
        Index id = (y * width + x) * depth + z;
        Index idx = 4 * id;

        colors[idx+0] = static_cast<float>(data[i+1]) / 255.0f;
        colors[idx+1] = static_cast<float>(data[i+2]) / 255.0f;
        colors[idx+2] = static_cast<float>(data[i+3]) / 255.0f;
        // float opacity = colors[idx+3];
        colors[idx+3] = 1.0f;
        // colors[idx + 3] = std::min(1.0f, 1.0f/255.0f + opacity);
        // if (opacity < 1.0f/255.0f)
        //     selected.push_back(id);
        indices.push_back(id);

        x = y;
        y = z;
    }

    return true;
}
