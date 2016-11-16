#pragma once

#include <Algorithm2D.hh>

class Algorithm2DFourColors : public Algorithm2D {
public:
    Algorithm2DFourColors() {}
    virtual ~Algorithm2DFourColors() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors,
                       size_t width, size_t height);
};

