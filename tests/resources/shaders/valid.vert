#version 330 core

layout (location = 0) in vec3 position;

out vec4 vertColor;

uniform vec4 testPosition;

void main() {
  gl_Position = vec4(position, 1.0);
  vertColor = vec4(position, 1.0) + testPosition;
}
