#version 330 core

in vec4 vertColor;

out vec4 color;

uniform vec4 testVec4;

void main() {
  color = vertColor + testVec4;
}
