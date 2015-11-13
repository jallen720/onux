#include "gl/ShaderProgram.hpp"

#include <string>
#include <stdexcept>
#include <glm/gtc/type_ptr.hpp>

#include "gl/ShaderObject.hpp"
#include "utils/existsIn.hpp"

using std::vector;
using std::string;
using std::runtime_error;
using glm::value_ptr;
using glm::vec3;
using glm::vec4;
using glm::mat4;

namespace onux {

struct ShaderProgram::Impl {
  const ShaderProgram* self;

  Impl(const ShaderProgram* self);
  void attach(Objects objects) const;
  void link() const;
  void detach(Objects objects) const;
  void validateLinkStatus() const;
  const bool linkingSucceeded() const;
  const GLint getInt(const GLenum parameter) const;
  const string getInfoLog() const;
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
  return hasType(objects, GL_VERTEX_SHADER) &&
         hasType(objects, GL_FRAGMENT_SHADER);
}

static void validateRequiredTypes(ShaderProgram::Objects objects) {
  if (!hasRequiredTypes(objects)) {
    throw runtime_error(
      "A ShaderProgram requires atleast a vertex shader object and a fragment shader object."
    );
  }
}

static GLuint loadShaderProgram(ShaderProgram::Objects objects) {
  validateRequiredTypes(objects);
  return glCreateProgram();
}

ShaderProgram::ShaderProgram(Objects objects)
  : OpenGLData(loadShaderProgram(objects))
  , impl(new Impl(this)) {
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
  glUniform1i(impl->getUniformLocation(name), value);
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

ShaderProgram::Impl::Impl(const ShaderProgram* self)
  : self(self) {}

void ShaderProgram::Impl::attach(Objects objects) const {
  for (auto object : objects) {
    glAttachShader(self->getID(), object->getID());
  }
}

void ShaderProgram::Impl::link() const {
  glLinkProgram(self->getID());
}

void ShaderProgram::Impl::detach(Objects objects) const {
  for (auto object : objects) {
    glDetachShader(self->getID(), object->getID());
  }
}

void ShaderProgram::Impl::validateLinkStatus() const {
  if (!linkingSucceeded()) {
    throw runtime_error("ShaderProgram linking failed:\n" + getInfoLog());
  }
}

const bool ShaderProgram::Impl::linkingSucceeded() const {
  return getInt(GL_LINK_STATUS) == GL_TRUE;
}

const GLint ShaderProgram::Impl::getInt(const GLenum parameter) const {
  GLint value;
  glGetProgramiv(self->getID(), parameter, &value);
  return value;
}

const string ShaderProgram::Impl::getInfoLog() const {
  vector<GLchar> infoLog(getInt(GL_INFO_LOG_LENGTH));

  glGetProgramInfoLog(
    self->getID(),
    infoLog.size(),
    nullptr,
    &infoLog[0]
  );

  return string(infoLog.begin(), infoLog.end());
}

static const bool isValidLocation(const GLint location) {
  const static GLint UNKNOWN_LOCATION = -1;
  return location != UNKNOWN_LOCATION;
}

static void validateLocation(const GLint location, const string& name) {
  if (!isValidLocation(location)) {
    throw runtime_error("Failed to find location of uniform \"" + name + "\"!");
  }
}

const GLint ShaderProgram::Impl::getUniformLocation(const GLchar* name) const {
  const GLint location = glGetUniformLocation(self->getID(), name);
  validateLocation(location, name);
  return location;
}

} // namespace onux
