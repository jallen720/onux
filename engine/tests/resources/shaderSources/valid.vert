#version 330 core

layout (location = 0) in vec3 position;

out vec4 vertColor;

uniform int  validInt;
uniform vec3 validVec3;
uniform mat4 validMat4;

void main() {
    gl_Position = validMat4 * vec4(position + validVec3, validInt);
    vertColor = gl_Position;
}
