#include<iostream>
#include <Algo3DCubeContiFrebet.hh>

bool
Algo3DCubeContiFrebet::apply(Floats& vertices, Floats& colors, VertIndices& indices,
                             size_t width, size_t height, size_t depth) {
    make_vertices(vertices, width, height, depth);

    size_t size;
    const u8* data = loadDataRange(size);

    std::cerr << "#data: " << size << std::endl;
    std::cerr << "#colors: " << colors.size() << std::endl;

    typedef struct {
        u8 x, y, z, r, g, b;
    } void_;
    const size_t struct_size = sizeof (void_);

    for (size_t i = 0; i+struct_size < size; i += 1) {
        auto* cast = (void_*)(data + i);

        auto x = static_cast<Index>(cast->x);
        auto y = static_cast<Index>(cast->y);
        auto z = static_cast<Index>(cast->z);

        Index id = (y * width + x) * depth + z;
        Index idx = 3 * id;

        colors[idx+0] = static_cast<float>(cast->r) / 255.0f;
        colors[idx+1] = static_cast<float>(cast->g) / 255.0f;
        colors[idx+2] = static_cast<float>(cast->b) / 255.0f;

        indices.push_back(id);
    }

    std::cerr << "#indices: " << indices.size() << std::endl;

    return true;
}
