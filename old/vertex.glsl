#version 320 es

layout(location = 0) in vec3 vertexBuffer;
layout(location = 1) in vec3 vertexColors;

out vec3 fragmentColors;

void main() {
    gl_Position.xyz = vertexBuffer;
    gl_Position.w = 1.0;

    fragmentColors = vertexColors;
}
