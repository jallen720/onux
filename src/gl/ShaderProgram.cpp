#include "gl/ShaderProgram.hpp"

#include <string>
#include <glm/gtc/type_ptr.hpp>

#include "gl/ShaderObject.hpp"
#include "gl/utils/ObjectInfo.hpp"
#include "exceptions/Error.hpp"
#include "exceptions/argErrors/ArgFailedRequirement.hpp"
#include "utils/existsIn.hpp"

using std::vector;
using std::string;
using glm::value_ptr;
using glm::vec3;
using glm::vec4;
using glm::mat4;

namespace onux {

struct ShaderProgram::Impl {
  const GLuint     id;
  const ObjectInfo objectInfo;

  Impl(const GLuint id);
  void attach(Objects objects) const;
  void link() const;
  void detach(Objects objects) const;
  void validateLinkStatus() const;
  const bool linkingSucceeded() const;
  const GLint getUniformLocation(const GLchar* name) const;
};

static const bool hasType(ShaderProgram::Objects objects, const GLenum type) {
  return existsIn(objects, [&](auto object) {
    return object->getType() == type;
  });
}

static const bool hasRequiredTypes(ShaderProgram::Objects objects) {
  // The minimum requirements for a shader program to be created are a vertex shader object and a
  // fragment shader object.
  static const vector<GLenum> REQUIRED_TYPES {
    GL_VERTEX_SHADER,
    GL_FRAGMENT_SHADER,
  };

  return !existsIn(REQUIRED_TYPES, [&](const auto requiredType) {
    return !hasType(objects, requiredType);
  });
}

static void validateRequiredTypes(ShaderProgram::Objects objects) {
  if (!hasRequiredTypes(objects)) {
    throw ArgFailedRequirement(
      "objects",
      "ShaderProgram",
      "Must contain atleast 1 vertex & 1 fragment object."
    );
  }
}

static GLuint getValidShaderProgram(ShaderProgram::Objects objects) {
  validateRequiredTypes(objects);
  return glCreateProgram();
}

ShaderProgram::ShaderProgram(Objects objects)
  : OpenGLData(getValidShaderProgram(objects))
  , impl(new Impl(getID())) {
  impl->attach(objects);
  impl->link();
  impl->detach(objects);
  impl->validateLinkStatus();
}

ShaderProgram::~ShaderProgram() {
  glDeleteProgram(getID());
}

void ShaderProgram::use() const {
  glUseProgram(getID());
}

void ShaderProgram::setUniform(const GLchar* name, const GLint value) const {
  glUniform1i(
    impl->getUniformLocation(name),
    value
  );
}

void ShaderProgram::setUniform(const GLchar* name, const vec3& value) const {
  glUniform3f(
    impl->getUniformLocation(name),
    value.x,
    value.y,
    value.z
  );
}

void ShaderProgram::setUniform(const GLchar* name, const vec4& value) const {
  glUniform4f(
    impl->getUniformLocation(name),
    value.x,
    value.y,
    value.z,
    value.w
  );
}

void ShaderProgram::setUniform(
  const GLchar*   name,
  const mat4&     value,
  const GLboolean transpose
) const {
  static const GLsizei MATRIX_COUNT = 1;

  glUniformMatrix4fv(
    impl->getUniformLocation(name),
    MATRIX_COUNT,
    transpose,
    value_ptr(value)
  );
}

// Implementation

ShaderProgram::Impl::Impl(const GLuint id)
  : id(id)
  , objectInfo(
      this->id,
      glGetProgramiv,
      glGetProgramInfoLog
    ) {}

void ShaderProgram::Impl::attach(Objects objects) const {
  for (auto object : objects) {
    glAttachShader(id, object->getID());
  }
}

void ShaderProgram::Impl::link() const {
  glLinkProgram(id);
}

void ShaderProgram::Impl::detach(Objects objects) const {
  for (auto object : objects) {
    glDetachShader(id, object->getID());
  }
}

void ShaderProgram::Impl::validateLinkStatus() const {
  if (!linkingSucceeded()) {
    throw Error("ShaderProgram linking failed:\n" + objectInfo.getInfoLog());
  }
}

const bool ShaderProgram::Impl::linkingSucceeded() const {
  return objectInfo.getValue(GL_LINK_STATUS) == GL_TRUE;
}

static const void validateLocation(const GLint location, const string& name) {
  const static GLint UNKNOWN_LOCATION = -1;

  if (location == UNKNOWN_LOCATION) {
    throw Error("Failed to find location of uniform \"" + name + "\"!");
  }
}

const GLint ShaderProgram::Impl::getUniformLocation(const GLchar* name) const {
  const GLint location = glGetUniformLocation(id, name);
  validateLocation(location, name);
  return location;
}

} // namespace onux
