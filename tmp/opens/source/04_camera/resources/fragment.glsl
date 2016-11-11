#version 150

in vec3 carryColr;
out vec4 finalColor;

void main() {
    finalColor.xyz = carryColr;
    finalColor.w = 1.0;
}
