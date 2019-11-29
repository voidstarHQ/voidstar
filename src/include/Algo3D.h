#pragma once

#include <vector>

#include "src/include/Algorithm.h"

class Algo3D : public Algorithm {
public:
    virtual ~Algo3D() {}

    virtual SceneType sceneType() const { return SCENE_3D; }
    virtual bool apply(Floats& vertices, Floats& colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth) = 0;
};
