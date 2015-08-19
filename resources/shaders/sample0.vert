void main() {
  gl_Position = vec4(position, 1) + objectPosition;
  vertColor = color;
  vertTexCoord = texCoord;
}
