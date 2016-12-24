#pragma once

#include <Algo3DSphere.hh>

class Algo3DSphereContiBnW : public Algo3DSphere {
public:
    Algo3DSphereContiBnW() {}
    virtual ~Algo3DSphereContiBnW() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth);
};
