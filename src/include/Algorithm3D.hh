#pragma once

#include <Algorithm.hh>

class Algorithm3D : public Algorithm {
public:
    virtual ~Algorithm3D() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors,
                       size_t width, size_t height, size_t depth) = 0;
};
