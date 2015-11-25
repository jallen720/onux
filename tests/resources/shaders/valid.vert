#version 330 core

layout (location = 0) in vec3 position;

out vec4 vertColor;

uniform vec3 testVec3;
uniform mat4 testMat4;

void main() {
    gl_Position = testMat4 * vec4(position + testVec3, 1.0);
    vertColor = gl_Position;
}
