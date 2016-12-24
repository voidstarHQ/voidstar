#pragma once

#include <vector>
#include <cmath>

#include <Algo3D.hh>

class Algo3DSphere : public Algo3D {
public:
    virtual ~Algo3DSphere() {}

    virtual bool apply(GLfloat* vertices, GLfloat* colors, VertIndices& selected,
                       size_t width, size_t height, size_t depth) = 0;

protected:
    size_t
    make_vertices(GLfloat* vertices, size_t width __unused, size_t height __unused, size_t depth) {
        const int gradation = 100;
        const float PI = 2 * std::acos(0.0f);
        const float R = static_cast<float>(depth) / 2.0f;
        const float Theta = 1.333 * PI;
        const float Phi = 2 * PI;
        const float step_angle = PI / gradation;
        const float step_radius = R / gradation / 8;

        size_t pos = 0;
        for (float r = 0.0f; r < R; r += step_radius)
            for (float theta = 0.0f; theta < Theta; theta += step_angle)
                for (float phi = 0.0f; phi < Phi; phi += step_angle) {
                    vertices[pos++] = r * std::sin(theta) * std::cos(phi);
                    vertices[pos++] = r * std::sin(theta) * std::sin(phi);
                    vertices[pos++] = r * std::cos(theta);
                }

        return pos / 3;
    }
};
