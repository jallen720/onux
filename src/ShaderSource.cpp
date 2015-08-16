#include "ShaderSource.hpp"

#include <stdexcept>

#include "helpers.hpp"
#include "loggers.hpp"

using std::runtime_error;

ShaderSource::Types ShaderSource::types {
  { "vert", GL_VERTEX_SHADER          },
  { "tesc", GL_TESS_CONTROL_SHADER    },
  { "tese", GL_TESS_EVALUATION_SHADER },
  { "geom", GL_GEOMETRY_SHADER        },
  { "frag", GL_FRAGMENT_SHADER        },
  { "comp", GL_COMPUTE_SHADER         },
};

static const bool isValidExtension(const string& extension) {
  return ShaderSource::types.count(extension) > 0;
}

static void validateExtension(const string& extension) {
  if (!isValidExtension(extension))
    throw runtime_error(
      "\"" + extension + "\" is not a valid ShaderSource file extension!"
    );
}

static const string loadExtension(const string& path) {
  const string extension = fileExtension(path);
  validateExtension(extension);
  return extension;
}

static unsigned int idIndex = 0;

ShaderSource::ShaderSource(const string& path)
  : type(types.at(loadExtension(path)))
  , code(readFile(path))
  , id(idIndex++) {
  logCreation(id, "ShaderSource");
}

ShaderSource::~ShaderSource() {
  logDestruction(id, "ShaderSource");
}

const GLenum ShaderSource::getType() const {
  return type;
}

const GLchar* ShaderSource::getCode() const {
  return code.c_str();
}
