#version 330 core

layout (location = 0) in vec3 position;

out vec4 vertColor;

uniform vec3 testPosition;

void main() {
  gl_Position = vec4(position + testPosition, 1.0);
  vertColor = gl_Position;
}
