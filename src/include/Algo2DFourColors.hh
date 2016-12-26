#pragma once

#include <Algo2D.hh>

class Algo2DFourColors : public Algo2D {
public:
    Algo2DFourColors() {}
    virtual ~Algo2DFourColors() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors,
                       size_t width, size_t height);
};
