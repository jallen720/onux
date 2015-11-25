#version 330 core

layout (location = 0) in vec3 position;

out vec4 vertColor;

// Uniform that isn't used; optimized out by OpenGL.
uniform vec3 unusedVec3;

void main() {
    gl_Position = vec4(position, 1.0);
    vertColor = vec4(position, 1.0);
}
