#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

out vec2 vertUV;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

vec4 vertexPosition() {
  vec3 samp = normal;
  return projection * view * model * vec4(position, 1);
}
