uniform sampler2D texture0;

void main() {
  gl_FragColor = texture(texture0, vertTexCoord) * vertColor;
}
