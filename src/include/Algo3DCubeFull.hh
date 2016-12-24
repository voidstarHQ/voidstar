#pragma once

#include <Algo3DCube.hh>

class Algo3DCubeFull : public Algo3DCube {
public:
    Algo3DCubeFull() {}
    virtual ~Algo3DCubeFull() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth);
};
