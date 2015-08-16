vec3 adjustedPosition() {
  return position + vec3(0.5, 0.5, 0.0);
}

void main() {
  gl_Position = vec4(position, 1.0);
  vertColor = vec4(adjustedPosition(), 1.0);
}
