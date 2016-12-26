#pragma once

#include <Algo3DCube.hh>

class Algo3DCubeContiFrebet : public Algo3DCube {
public:
    Algo3DCubeContiFrebet() {}
    virtual ~Algo3DCubeContiFrebet() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth);
};
