#pragma once
#include <string>

static const std::string shader__fragment = R"(\
#version 150

in vec3 carryColr;
out vec4 finalColor;

void main() {
    finalColor = vec4(carryColr, 1);
}
)";


static const std::string shader__vertex_2d = R"(\
#version 150

in vec2 vert;

in vec3 colr;
out vec3 carryColr;

void main() {
    // Pass colr through to fragment shader
    carryColr = colr;

    gl_PointSize = 4;

    // Apply all matrix transformations to vert
    gl_Position = vec4(vert, 0, 1);
}
)";


static const std::string shader__vertex_3d = R"(\
#version 150

uniform mat4 camera;
uniform mat4 model;

in vec3 vert;

in vec3 colr;
out vec3 carryColr;

void main() {
    // Pass colr through to fragment shader
    carryColr = colr;

    // Apply all matrix transformations to vert
    gl_Position = camera * model * vec4(vert, 1);
}
)";

