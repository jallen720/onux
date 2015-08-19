#include "onux_gl/Texture.hpp"

#include "onux_gl/IImage.hpp"

namespace onux_gl {
  const Texture::Options Texture::DEFAULT_OPTIONS {
    { GL_TEXTURE_MIN_FILTER, GL_LINEAR },
    { GL_TEXTURE_MAG_FILTER, GL_LINEAR },
  };

  static GLuint newTexture() {
    GLuint id;
    glGenTextures(1, &id);
    return id;
  }

  void Texture::loadImage(const IImage& image) const {
    static const GLint  LEVEL_OF_DETAIL = 0; // 0 is base image LOD
    static const GLint  INTERNAL_FORMAT = GL_RGBA;
    static const GLint  BORDER_WIDTH    = 0; // Must be 0 apparently?
    static const GLenum TEXEL_DATA_TYPE = GL_UNSIGNED_BYTE;

    // Load texture data from image
    glTexImage2D(
      TARGET,            // Target
      LEVEL_OF_DETAIL,   // Level of detail
      INTERNAL_FORMAT,   // Internal format
      image.getWidth(),  // Image width
      image.getHeight(), // Image height
      BORDER_WIDTH,      // Border width
      INTERNAL_FORMAT,   // Texel data format (must match internal format)
      TEXEL_DATA_TYPE,   // Texel data type
      image.getData()    // Pointer to image data
    );
  }

  void Texture::loadOptions(const Options& options) const {
    for (auto option : options)
      glTexParameteri(TARGET, option.first, option.second);
  }

  Texture::Texture(const IImage& image, const Options& options)
    : OpenGLData(newTexture()) {
    bind(0);
    loadImage(image);
    loadOptions(options);
  }

  Texture::~Texture() {
    glDeleteTextures(1, &getID());
  }

  void Texture::bind(const unsigned int unit) const {
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(TARGET, getID());
  }
}
