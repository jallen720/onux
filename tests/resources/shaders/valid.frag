#version 330 core

in vec4 vertColor;

out vec4 color;

uniform vec4 testColor;

void main() {
  color = vertColor + testColor;
}
