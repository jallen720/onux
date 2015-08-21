#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texCoord;

out vec4 vertColor;
out vec2 vertTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

vec4 vertexPosition() {
  return projection * view * model * vec4(position, 1);
}
