#include "gl/Texture.hpp"

#include "gl/interfaces/IImage.hpp"

namespace onux {

struct Texture::Impl {
  void loadImage(const IImage* image) const;
  void loadOptions(Options& options) const;
};

// Texture represents 1 texture.
static const GLsizei TEXTURE_COUNT = 1;

static GLuint newTexture() {
  GLuint id;
  glGenTextures(TEXTURE_COUNT, &id);
  return id;
}

Texture::Texture(const IImage* image, Options& options)
  : OpenGLData(newTexture())
  , impl(new Impl()) {
  bind(0);
  impl->loadImage(image);
  impl->loadOptions(options);
}

Texture::~Texture() {
  glDeleteTextures(TEXTURE_COUNT, &getID());
}

static const GLenum TARGET = GL_TEXTURE_2D;

void Texture::bind(const GLuint unit) const {
  glActiveTexture(GL_TEXTURE0 + unit);
  glBindTexture(TARGET, getID());
}

Texture::Options Texture::DEFAULT_OPTIONS {
  { GL_TEXTURE_MIN_FILTER, GL_LINEAR },
  { GL_TEXTURE_MAG_FILTER, GL_LINEAR },
};

// Implementation

void Texture::Impl::loadImage(const IImage* image) const {
  static const GLint  LEVEL_OF_DETAIL = 0; // 0 is base image LOD
  static const GLint  INTERNAL_FORMAT = GL_RGBA;
  static const GLint  BORDER_WIDTH    = 0; // Must be 0 apparently?
  static const GLenum TEXEL_DATA_TYPE = GL_UNSIGNED_BYTE;

  // Load texture data from image
  glTexImage2D(
    TARGET,             // Target
    LEVEL_OF_DETAIL,    // Level of detail
    INTERNAL_FORMAT,    // Internal format
    image->getWidth(),  // Image width
    image->getHeight(), // Image height
    BORDER_WIDTH,       // Border width
    INTERNAL_FORMAT,    // Texel data format (must match internal format)
    TEXEL_DATA_TYPE,    // Texel data type
    image->getData()    // Pointer to image data
  );
}

void Texture::Impl::loadOptions(Options& options) const {
  for (auto option : options) {
    glTexParameteri(
      TARGET,
      option.first,
      option.second
    );
  }
}

} // namespace onux
