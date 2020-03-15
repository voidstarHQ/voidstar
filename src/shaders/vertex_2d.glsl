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
