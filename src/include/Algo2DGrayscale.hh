#pragma once

#include <Algo2D.hh>

class Algo2DGrayscale : public Algo2D {
public:
    Algo2DGrayscale() {}
    virtual ~Algo2DGrayscale() {}

    virtual bool apply(std::shared_ptr<GLfloat> vertices, std::shared_ptr<GLfloat> colors,
                       size_t width, size_t height);
};
