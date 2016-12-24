#pragma once

#include <Algo3DSphere.hh>

class Algo3DSphereContiFrebet : public Algo3DSphere {
public:
    Algo3DSphereContiFrebet() {}
    virtual ~Algo3DSphereContiFrebet() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth);
};
