#pragma once

#include <Algo3DCube.hh>

class Algo3DCubeEntropy : public Algo3DCube {
public:
    Algo3DCubeEntropy() {}
    virtual ~Algo3DCubeEntropy() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth);
};

