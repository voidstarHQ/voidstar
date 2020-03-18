#version 330 core

layout (location = 0) in vec2 vert;
layout (location = 1) in vec3 colr;

out vec3 carryColr;

void main() {
    gl_Position = vec4(vert, 0, 1);
    gl_PointSize = 4;

    // Pass colr through to fragment shader
    carryColr = colr;
}
