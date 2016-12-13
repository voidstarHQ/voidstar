#pragma once

#include <Algorithm3D.hh>

class Algorithm3DContiFrebet : public Algorithm3D {
public:
    Algorithm3DContiFrebet() {}
    virtual ~Algorithm3DContiFrebet() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth);
};

