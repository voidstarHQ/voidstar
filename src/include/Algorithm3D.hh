#pragma once

#include <vector>

#include <Algorithm.hh>

typedef std::vector<unsigned int> VertIndices;

class Algorithm3D : public Algorithm {
public:
    virtual ~Algorithm3D() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth) = 0;
};
