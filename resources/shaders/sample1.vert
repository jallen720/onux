void main() {
  gl_Position = vertexPosition();
  vertColor = color * gl_Position;
  vertTexCoord = texCoord;
}
