out vec4 color;

uniform vec4 ourColor;

void main() {
  color = vec4(vertColor.r, ourColor.g, vertColor.ba);
}
