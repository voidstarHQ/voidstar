#pragma once

#include "src/include/Algorithm.h"

class Algo2D : public Algorithm {
public:
    virtual ~Algo2D() {}

    virtual SceneType sceneType() const { return SCENE_2D; }
    virtual bool apply(Floats& vertices, Floats& colors,
                       size_t width, size_t height) = 0;

protected:
    size_t
    make_vertices(Floats& vertices, size_t width, size_t height) {
        const float w = static_cast<float>(width) / 2;
        const float h = static_cast<float>(height) / 2;

        size_t pos = 0;
        for (size_t y = 0; y < height; ++y)
            for (size_t x = 0; x < width; ++x) {
                vertices[pos++] = (static_cast<float>(x) - w) / w;
                vertices[pos++] = (static_cast<float>(y) - h) / h;
            }
        return vertices.size() / 2;
    }
};
