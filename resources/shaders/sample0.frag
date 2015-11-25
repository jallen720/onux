uniform sampler2D texture0;
uniform sampler2D texture1;

vec4 mixedTextures() {
    return mix(
        texture(texture0, vertUV),
        texture(texture1, vertUV),
        0.5
    );
}

void main() {
    gl_FragColor = mixedTextures();
}
