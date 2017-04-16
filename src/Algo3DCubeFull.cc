#include <Algo3DCubeFull.hh>

bool
Algo3DCubeFull::apply(std::shared_ptr<GLfloat> vertices, std::shared_ptr<GLfloat> colors,
                      VertIndices& selected,
                      size_t width, size_t height, size_t depth) {
    auto nb_verts = make_vertices(vertices, width, height, depth);

    for (size_t i = 0; i < nb_verts; ++i) {
        colors[3 * i + 0] = 1.0f;
        colors[3 * i + 1] = 1.0f;
        colors[3 * i + 2] = 1.0f;
        colors[3 * i + 3] = 1.0f;
        selected.push_back(i);
    }

    return true;
}
