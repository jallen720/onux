#include "graphics/ShaderSource.hpp"

#include <stdexcept>

#include "utils/helpers.hpp"

using std::string;
using std::runtime_error;

namespace onux {

ShaderSource::Types ShaderSource::TYPES {
  { "vert", GL_VERTEX_SHADER          },
  { "tesc", GL_TESS_CONTROL_SHADER    },
  { "tese", GL_TESS_EVALUATION_SHADER },
  { "geom", GL_GEOMETRY_SHADER        },
  { "frag", GL_FRAGMENT_SHADER        },
  { "comp", GL_COMPUTE_SHADER         },
};

static const bool isValidExtension(const string& extension) {
  return ShaderSource::TYPES.count(extension) == 1;
}

static void validateExtension(const string& extension) {
  if (!isValidExtension(extension)) {
    throw runtime_error(
      "\"" + extension + "\" is not a valid ShaderSource file extension!"
    );
  }
}

static const string loadExtension(const string& path) {
  const string extension = fileExtension(path);
  validateExtension(extension);
  return extension;
}

ShaderSource::ShaderSource(const string& path)
  : m_type(TYPES.at(loadExtension(path)))
  , m_code(readFile(path)) {}

const GLenum ShaderSource::getType() const {
  return m_type;
}

const GLchar* ShaderSource::getCode() const {
  return m_code.c_str();
}

} // namespace onux
