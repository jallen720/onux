#include "gl/Texture.hpp"

#include <map>
#include <string>
#include <vector>
#include <stdexcept>

#include "gl/interfaces/IImage.hpp"
#include "utils/contains.hpp"
#include "exceptions/NullArg.hpp"
#include "exceptions/InvalidMapKey.hpp"
#include "exceptions/InvalidMapValue.hpp"
#include "utils/map.hpp"
#include "gl/utils/getEnumName.hpp"

using std::string;
using std::vector;
using std::runtime_error;

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
    throw NullArg("image", "Texture");
  }
}

static const vector<GLenum> VALID_OPTION_KEYS {
  GL_TEXTURE_MIN_FILTER,
  GL_TEXTURE_MAG_FILTER,
  GL_TEXTURE_WRAP_S,
  GL_TEXTURE_WRAP_T,
};

static void validateOptionKey(const GLenum optionKey) {
  if (!contains(VALID_OPTION_KEYS, optionKey)) {
    throw InvalidMapKey(
      "options",
      "Texture",
      getEnumName(optionKey),
      map<string>(VALID_OPTION_KEYS, getEnumName)
    );
  }
}

static const vector<GLint> VALID_WRAP_VALUES {
  GL_CLAMP_TO_EDGE,
  GL_MIRRORED_REPEAT,
  GL_REPEAT,
};

static const vector<GLint> VALID_MIN_FILTER_VALUES {
  GL_NEAREST,
  GL_LINEAR,
  GL_NEAREST_MIPMAP_NEAREST,
  GL_LINEAR_MIPMAP_NEAREST,
  GL_NEAREST_MIPMAP_LINEAR,
  GL_LINEAR_MIPMAP_LINEAR,
};

static const vector<GLint> VALID_MAG_FILTER_VALUES {
  GL_NEAREST,
  GL_LINEAR,
};

static const std::map<const GLenum, vector<GLint>> VALID_OPTION_VALUES {
  { GL_TEXTURE_WRAP_S    , VALID_WRAP_VALUES       },
  { GL_TEXTURE_WRAP_T    , VALID_WRAP_VALUES       },
  { GL_TEXTURE_MIN_FILTER, VALID_MIN_FILTER_VALUES },
  { GL_TEXTURE_MAG_FILTER, VALID_MAG_FILTER_VALUES },
};

static void validateOptionValue(const GLenum optionKey, const GLint optionValue) {
  if (!contains(VALID_OPTION_VALUES.at(optionKey), optionValue)) {
    throw InvalidMapValue(
      "options",
      "Texture",
      getEnumName(optionKey),
      getEnumName(optionValue),
      map<string>(VALID_OPTION_VALUES.at(optionKey), getEnumName)
    );
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
