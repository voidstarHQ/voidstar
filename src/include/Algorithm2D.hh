#pragma once

#include <Algorithm.hh>

class Algorithm2D : public Algorithm {
public:
    virtual ~Algorithm2D() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors,
                       size_t width, size_t height) = 0;
};
