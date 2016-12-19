#pragma once

#include <vector>

#include <Algorithm.hh>

using VertIndices = std::vector<unsigned int>;

class Algo3D : public Algorithm {
public:
    virtual ~Algo3D() {}

    virtual SceneType sceneType() const { return SCENE_3D; }
    virtual bool apply(GLfloat* vertices, GLfloat* colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth) = 0;

    void make_vertices(GLfloat* vertices, size_t width, size_t height, size_t depth) {
        size_t pos = 0;
        for (size_t z = 0; z < depth; ++z)
            for (size_t y = 0; y < height; ++y)
                for (size_t x = 0; x < width; ++x) {
                    vertices[pos++] = ((float)x - (float)width  / 2.0f) / 128;
                    vertices[pos++] = ((float)y - (float)height / 2.0f) / 128;
                    vertices[pos++] = ((float)z - (float)depth  / 2.0f) / 128;
                }
    }
};
