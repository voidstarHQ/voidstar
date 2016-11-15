#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Algorithm.hh>

class Algorithm2D : public Algorithm {
public:
    virtual ~Algorithm2D() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors,
                       size_t width, size_t height) = 0;
};
