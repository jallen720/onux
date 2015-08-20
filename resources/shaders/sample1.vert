vec4 adjustedPosition() {
  return gl_Position + vec4(0.75, 0.75, 0, 0);
}

void main() {
  gl_Position = vertexPosition();
  vertColor = color * adjustedPosition().bgra;
  vertTexCoord = texCoord;
}
