#include "graphics/ShaderSource.hpp"

#include "utils/helpers.hpp"
#include "exceptions/InvalidArgProperty.hpp"
#include "exceptions/InvalidArg.hpp"
#include "utils/keys.hpp"

using std::string;

namespace onux {

struct ShaderSource::Impl {
  const GLenum type;
  const string code;

  Impl(const string& path);
};

ShaderSource::Types ShaderSource::TYPES {
  { "vert", GL_VERTEX_SHADER          },
  { "tesc", GL_TESS_CONTROL_SHADER    },
  { "tese", GL_TESS_EVALUATION_SHADER },
  { "geom", GL_GEOMETRY_SHADER        },
  { "frag", GL_FRAGMENT_SHADER        },
  { "comp", GL_COMPUTE_SHADER         },
};

static void validatePath(const string& path) {
  if (path.empty()) {
    throw InvalidArg("path", "ShaderSource", "\"\"", "non-empty");
  }
}

static const string& getValidPath(const string& path) {
  validatePath(path);
  return path;
}

ShaderSource::ShaderSource(const string& path)
  : impl(new Impl(getValidPath(path))) {}

const GLenum ShaderSource::getType() const {
  return impl->type;
}

const GLchar* ShaderSource::getCode() const {
  return impl->code.c_str();
}

// Implementation

static const bool isValidExtension(const string& extension) {
  return ShaderSource::TYPES.count(extension) == 1;
}

static void validateExtension(const string& extension) {
  if (!isValidExtension(extension)) {
    throw InvalidArgProperty(
      "path",
      "ShaderSource",
      "extension",
      extension,
      keys(ShaderSource::TYPES)
    );
  }
}

static const GLenum getValidType(const string& path) {
  const string extension = fileExtension(path);
  validateExtension(extension);
  return ShaderSource::TYPES.at(extension);
}

ShaderSource::Impl::Impl(const string& path)
  : type(getValidType(path))
  , code(readFile(path)) {}

} // namespace onux
