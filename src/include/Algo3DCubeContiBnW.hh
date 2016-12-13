#pragma once

#include <Algo3DCube.hh>

class Algo3DCubeContiBnW : public Algo3DCube {
public:
    Algo3DCubeContiBnW() {}
    virtual ~Algo3DCubeContiBnW() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth);
};

