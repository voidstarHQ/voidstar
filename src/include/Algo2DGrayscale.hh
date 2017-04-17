#pragma once

#include <Algo2D.hh>

class Algo2DGrayscale : public Algo2D {
public:
    Algo2DGrayscale() {}
    virtual ~Algo2DGrayscale() {}

    virtual bool apply(Floats& vertices, Floats& colors,
                       size_t width, size_t height);
};
