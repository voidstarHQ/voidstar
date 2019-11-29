#pragma once

#include "src/include/Algo3DSphere.h"

class Algo3DSphereContiFrebet : public Algo3DSphere {
public:
    Algo3DSphereContiFrebet() {}
    virtual ~Algo3DSphereContiFrebet() {}

    virtual bool apply(Floats& vertices, Floats& colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth);
};
