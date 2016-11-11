#version 150

uniform mat4 camera;
uniform mat4 model;

in vec3 vert;

in vec4 colr;
out vec4 carryColr;

void main() {
    // Pass colr through to fragment shader
    carryColr = colr;

    // Apply all matrix transformations to vert
    gl_Position = camera * model * vec4(vert, 1);
}
