void main() {
  gl_Position = vec4(position + objectPosition, 1);
  vertColor = color;
  vertTexCoord = texCoord;
}
