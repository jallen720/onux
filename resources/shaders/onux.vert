#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texCoord;

out vec4 vertColor;
out vec2 vertTexCoord;

uniform mat4 transform;

vec4 vertexPosition() {
  return transform * vec4(position, 1);
}
