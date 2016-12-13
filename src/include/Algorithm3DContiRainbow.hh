#pragma once

#include <Algorithm3D.hh>

class Algorithm3DContiRainbow : public Algorithm3D {
public:
    Algorithm3DContiRainbow() {}
    virtual ~Algorithm3DContiRainbow() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth);
};

