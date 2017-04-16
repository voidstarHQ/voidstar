#pragma once

#include <Algo2D.hh>

class Algo2DFourColors : public Algo2D {
public:
    Algo2DFourColors() {}
    virtual ~Algo2DFourColors() {}

    virtual bool apply(std::unique_ptr<GLfloat[]> vertices, std::unique_ptr<GLfloat[]> colors,
                       size_t width, size_t height);
};
