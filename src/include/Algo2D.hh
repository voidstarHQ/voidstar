#pragma once

#include <Algorithm.hh>

class Algo2D : public Algorithm {
public:
    virtual ~Algo2D() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors,
                       size_t width, size_t height) = 0;
};
