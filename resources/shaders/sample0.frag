out vec4 color;

uniform vec4 ourColor;

void main() {
  color = texture(texture0, vertTexCoord) * vec4(vertColor.r, ourColor.g, vertColor.ba);
}
