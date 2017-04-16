#pragma once

#include <vector>

#include <Algo3D.hh>

class Algo3DCube : public Algo3D {
public:
    virtual ~Algo3DCube() {}

    virtual bool apply(Floats& vertices, Floats& colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth) = 0;

protected:
    size_t
    make_vertices(Floats& vertices, size_t width, size_t height, size_t depth) {
        const float w = static_cast<float>(width) / 2;
        const float h = static_cast<float>(height) / 2;
        const float d = static_cast<float>(depth) / 2;

        size_t pos = 0;
        for (size_t z = 0; z < depth; ++z)
            for (size_t y = 0; y < height; ++y)
                for (size_t x = 0; x < width; ++x) {
                    vertices[pos++] = (static_cast<float>(x) - w) / w;
                    vertices[pos++] = (static_cast<float>(y) - h) / h;
                    vertices[pos++] = (static_cast<float>(z) - d) / d;
                }

        return pos / 3;
    }
};
