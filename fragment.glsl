#version 320 es

precision lowp float;

in vec3 fragmentColors;
out vec3 color;

void main() {
    //color = fragmentColors;
    color = vec3(1,0,0);
}
