#include "ShaderProgram.hpp"

#include <string>
#include <stdexcept>

#include "ShaderObject.hpp"
#include "loggers.hpp"

using std::string;
using std::runtime_error;

static const bool isValidLocation(const GLint location) {
  const static GLint UNKNOWN_LOCATION = -1;
  return location != UNKNOWN_LOCATION;
}

static void validateLocation(const GLint location, const string& name) {
  if (!isValidLocation(location))
    throw runtime_error("Failed to find location of uniform \"" + name + "\"!");
}

static const bool hasType(ShaderProgram::Objects objects, const GLenum type) {
  for (auto object : objects)
    if (object->getType() == type)
      return true;

  return false;
}

static const bool hasRequiredTypes(ShaderProgram::Objects objects) {
  // The minimum requirements for a shader program to be created are a vertex
  // shader object and a fragment shader object.
  return hasType(objects, GL_VERTEX_SHADER) &&
         hasType(objects, GL_FRAGMENT_SHADER);
}

static void validateRequiredTypes(ShaderProgram::Objects objects) {
  if (!hasRequiredTypes(objects))
    throw runtime_error(
      "A ShaderProgram requires atleast a vertex shader object "
      "and a fragment shader object."
    );
}

void ShaderProgram::attach(Objects objects) const {
  for (auto object : objects)
    glAttachShader(getID(), object->getID());
}

void ShaderProgram::link() const {
  glLinkProgram(getID());
}

void ShaderProgram::detach(Objects objects) const {
  for (auto object : objects)
    glDetachShader(getID(), object->getID());
}

void ShaderProgram::validateLinkStatus() const {
  if (!linkingSucceeded())
    throw runtime_error("ShaderProgram linking failed:\n" + getInfoLog());
}

const bool ShaderProgram::linkingSucceeded() const {
  return getInt(GL_LINK_STATUS) == GL_TRUE;
}

const GLint ShaderProgram::getInt(const GLenum parameter) const {
  GLint value;
  glGetProgramiv(getID(), parameter, &value);
  return value;
}

const string ShaderProgram::getInfoLog() const {
  vector<GLchar> infoLog(getInt(GL_INFO_LOG_LENGTH));
  glGetProgramInfoLog(getID(), infoLog.size(), nullptr, &infoLog[0]);
  return string(infoLog.begin(), infoLog.end());
}

const GLint ShaderProgram::getUniformLocation(const GLchar* name) const {
  const GLint location = glGetUniformLocation(getID(), name);
  validateLocation(location, name);
  return location;
}

ShaderProgram::ShaderProgram(Objects objects)
  : OpenGLData(glCreateProgram()) {
  validateRequiredTypes(objects);
  attach(objects);
  link();
  detach(objects);
  validateLinkStatus();
  logCreation(this, "ShaderProgram");
}

ShaderProgram::~ShaderProgram() {
  logDestruction(this, "ShaderProgram");
  glDeleteProgram(getID());
}

void ShaderProgram::use() const {
  glUseProgram(getID());
}

void ShaderProgram::setUniform(const GLchar* name, const vec3& value) const {
  glUniform3f(getUniformLocation(name), value.x, value.y, value.z);
}

void ShaderProgram::setUniform(const GLchar* name, const GLint value) const {
  glUniform1i(getUniformLocation(name), value);
}
