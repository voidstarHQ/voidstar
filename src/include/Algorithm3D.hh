#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Algorithm.hh>

class Algorithm3D : public Algorithm {
public:
    virtual ~Algorithm3D() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors,
                       size_t width, size_t height, size_t depth) = 0;
};
