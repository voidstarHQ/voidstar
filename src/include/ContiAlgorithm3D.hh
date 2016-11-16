#pragma once

#include <Algorithm3D.hh>

class ContiAlgorithm3D : public Algorithm3D {
public:
    ContiAlgorithm3D() {}
    virtual ~ContiAlgorithm3D() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors,
                       size_t width, size_t height, size_t depth);
};

