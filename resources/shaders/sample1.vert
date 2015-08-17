vec4 adjustedPosition() {
  return gl_Position + vec4(1, 1, 0.0, 0.0);
}

void main() {
  gl_Position = vec4(position, 1.0) + objectPosition;
  vertColor = vec4(color, 1.0) * adjustedPosition();
}
