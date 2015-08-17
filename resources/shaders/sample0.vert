void main() {
  gl_Position = vec4(position, 1.0) + objectPosition;
  vertColor = vec4(color, 1.0);
}
