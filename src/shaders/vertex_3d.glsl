#version 330 core

layout (location = 0) in vec3 vert;
layout (location = 1) in vec3 colr;

out vec3 carryColr;

uniform mat4 uMVP;

void main() {
    gl_Position = uMVP * vec4(vert, 1);

    // Pass colr through to fragment shader
    carryColr = colr;
}
