#pragma once

#include <Algorithm2D.hh>

class Algorithm2DGrayscale : public Algorithm2D {
public:
    Algorithm2DGrayscale() {}
    virtual ~Algorithm2DGrayscale() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors,
                       size_t width, size_t height);
};

