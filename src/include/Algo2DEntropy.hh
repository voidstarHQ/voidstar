#pragma once

#include <Algo2D.hh>

class Algo2DEntropy : public Algo2D {
public:
    Algo2DEntropy() {}
    virtual ~Algo2DEntropy() {}

    virtual bool apply(std::unique_ptr<GLfloat[]> vertices, std::unique_ptr<GLfloat[]> colors,
                       size_t width, size_t height);
};
