#pragma once

#include <vector>

#include <Algorithm.hh>

typedef std::vector<unsigned int> VertIndices;

class Algo3DCube : public Algorithm {
public:
    virtual ~Algo3DCube() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth) = 0;
};
