#version 150

in vec3 carryColr;
out vec4 finalColor;

void main() {
    finalColor = vec4(carryColr, 1);
}
