#pragma once

#include <Algo3DSphere.hh>

class Algo3DSphereFull : public Algo3DSphere {
public:
    Algo3DSphereFull() {}
    virtual ~Algo3DSphereFull() {}

    virtual bool apply(std::unique_ptr<GLfloat[]> vertices, std::unique_ptr<GLfloat[]> colors,
                       VertIndices& selected,
                       size_t width, size_t height, size_t depth);
};
