#pragma once

#include <cmath>
#include <vector>

#include "voidstar/algos_3d/algo_3d.h"

class Algo3DSphere : public Algo3D {
 public:
  virtual ~Algo3DSphere() {}

  virtual bool apply(Floats& vertices, Floats& colors, VertIndices& selected,
                     u32 width, u32 height, u32 depth) = 0;

 protected:
  u32 make_vertices(Floats& vertices, u32 width, u32 height, u32 depth) {
    const double w = static_cast<double>(width) / 2;
    const double h = static_cast<double>(height) / 2;
    const double d = static_cast<double>(depth) / 2;
    const int gradation = 100;
    const double PI = M_PI;
    const double R = static_cast<double>(depth) / 2.0f;
    const double Theta = 1.333 * PI;
    const double Phi = 2 * PI;
    const double step_angle = PI / gradation;
    const double step_radius = R / gradation / 8;

    size_t pos = 0;
    for (double r = 0.0f; r < R; r += step_radius)
      for (double theta = 0.0f; theta < Theta; theta += step_angle)
        for (double phi = 0.0f; phi < Phi; phi += step_angle) {
          vertices[pos++] =
              static_cast<float>(r * std::sin(theta) * std::cos(phi) / w);
          vertices[pos++] =
              static_cast<float>(r * std::sin(theta) * std::sin(phi) / h);
          vertices[pos++] = static_cast<float>(r * std::cos(theta) / d);
        }

    return static_cast<u32>(vertices.size()) / 3;
  }
};
