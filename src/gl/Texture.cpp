#include "gl/Texture.hpp"

#include <map>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include "gl/interfaces/IImage.hpp"

using std::map;
using std::vector;
using std::runtime_error;
using std::find;
using std::begin;
using std::end;

namespace onux {

struct Texture::Impl {
  void loadImage(const IImage* image) const;
  void loadOptions(Options& options) const;
};

// Texture represents 1 texture.
static const GLsizei TEXTURE_COUNT = 1;

static GLuint createTexture() {
  GLuint id;
  glGenTextures(TEXTURE_COUNT, &id);
  return id;
}

static void validateImage(const IImage* image) {
  if (image == nullptr) {
    throw runtime_error("'image' parameter passed to Texture is null!");
  }
}

static bool isValidOptionKey(const GLenum optionKey) {
  static const GLenum VALID_OPTION_KEYS[] {
    GL_TEXTURE_MIN_FILTER,
    GL_TEXTURE_MAG_FILTER,
    GL_TEXTURE_WRAP_S,
    GL_TEXTURE_WRAP_T,
  };

  return find(
    begin(VALID_OPTION_KEYS),
    end(VALID_OPTION_KEYS),
    optionKey
  ) != end(VALID_OPTION_KEYS);
}

static void validateOptionKey(const GLenum optionKey) {
  if (!isValidOptionKey(optionKey)) {
    throw runtime_error("Invalid option key passed to Texture!");
  }
}

static bool isValidOptionValue(const GLenum optionKey, const GLint optionValue) {
  static const vector<GLint> VALID_WRAP_VALUES {
    GL_CLAMP_TO_EDGE,
    GL_MIRRORED_REPEAT,
    GL_REPEAT,
  };

  static const map<const GLenum, vector<GLint>> VALID_OPTION_VALUES {
    { GL_TEXTURE_MIN_FILTER, {
      GL_NEAREST,
      GL_LINEAR,
      GL_NEAREST_MIPMAP_NEAREST,
      GL_LINEAR_MIPMAP_NEAREST,
      GL_NEAREST_MIPMAP_LINEAR,
      GL_LINEAR_MIPMAP_LINEAR,
    }},
    { GL_TEXTURE_MAG_FILTER, {
      GL_NEAREST,
      GL_LINEAR,
    }},
    { GL_TEXTURE_WRAP_S, VALID_WRAP_VALUES },
    { GL_TEXTURE_WRAP_T, VALID_WRAP_VALUES },
  };

  const auto& values = VALID_OPTION_VALUES.at(optionKey);

  return find(
    values.begin(),
    values.end(),
    optionValue
  ) != values.end();
}

static void validateOptionValue(const GLenum optionKey, const GLint optionValue) {
  if (!isValidOptionValue(optionKey, optionValue)) {
    throw runtime_error("Invalid option value passed to Texture!");
  }
}

static void validateOptions(Texture::Options& options) {
  for (auto option : options) {
    validateOptionKey(option.first);
    validateOptionValue(option.first, option.second);
  }
}

static GLuint loadTexture(const IImage* image, Texture::Options& options) {
  validateImage(image);
  validateOptions(options);
  return createTexture();
}

Texture::Texture(const IImage* image, Options& options)
  : OpenGLData(loadTexture(image, options))
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
