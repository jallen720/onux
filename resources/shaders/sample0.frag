uniform sampler2D texture0;
uniform sampler2D texture1;

vec4 mixedTextures() {
  return mix(
    texture(texture0, vertTexCoord),
    texture(texture1, vertTexCoord),
    0.5
  );
}

void main() {
  gl_FragColor = mixedTextures() * vertColor;
}
