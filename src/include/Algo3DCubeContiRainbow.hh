#pragma once

#include <Algo3DCube.hh>

class Algo3DCubeContiRainbow : public Algo3DCube {
public:
    Algo3DCubeContiRainbow() {}
    virtual ~Algo3DCubeContiRainbow() {}

    virtual bool apply(std::shared_ptr<GLfloat> vertices, std::shared_ptr<GLfloat> colors,
                       VertIndices& selected,
                       size_t width, size_t height, size_t depth);
};
