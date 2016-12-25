#version 150

in vec2 vert;

in vec4 colr;
out vec4 carryColr;

void main() {
    // Pass colr through to fragment shader
    carryColr = colr;

    gl_PointSize = 5;

    // Apply all matrix transformations to vert
    gl_Position = vec4(vert, 0, 1);
}
