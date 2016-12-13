#pragma once

#include <vector>

#include <Algo3D.hh>

class Algo3DCube : public Algo3D {
public:
    virtual ~Algo3DCube() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth) = 0;
};
