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
};
