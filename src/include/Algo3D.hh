#pragma once

#include <vector>

#include <Algorithm.hh>

class Algo3D : public Algorithm {
public:
    virtual ~Algo3D() {}

    virtual SceneType sceneType() const { return SCENE_3D; }

    virtual size_t value_size() const = 0;
    virtual Index cast(const u8* data, Floats& colors,
                       size_t width, size_t height, size_t depth) const = 0;
};
