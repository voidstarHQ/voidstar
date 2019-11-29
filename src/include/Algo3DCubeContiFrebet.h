#pragma once

#include "src/include/Algo3DCube.h"

class Algo3DCubeContiFrebet : public Algo3DCube {
public:
    Algo3DCubeContiFrebet() {}
    virtual ~Algo3DCubeContiFrebet() {}

    virtual bool apply(Floats& vertices, Floats& colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth);
};
