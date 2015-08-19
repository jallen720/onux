out vec4 color;

void main() {
  color = texture(texture0, vertTexCoord) * vertColor;
}
