#pragma once

#include <Algorithm3D.hh>

class Algorithm3DContiBnW : public Algorithm3D {
public:
    Algorithm3DContiBnW() {}
    virtual ~Algorithm3DContiBnW() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth);
};

