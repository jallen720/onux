#include "ShaderObject.hpp"

#include <stdexcept>

#include "ShaderSource.hpp"

using std::runtime_error;

static void validateSameType(const GLenum type, ShaderObject::Sources sources) {
  for (auto source : sources)
    if (source->getType() != type)
      throw runtime_error(
        "All ShaderSource files for ShaderObject must have the same type!"
      );
}

static const bool isValidSourceCount(const size_t sourceCount) {
  static const size_t MIN_SOURCE_COUNT = 1;
  return sourceCount >= MIN_SOURCE_COUNT;
}

static void validateSourceCount(const size_t sourceCount) {
  if (!isValidSourceCount(sourceCount))
    throw runtime_error("ShaderObject requires atleast 1 ShaderSource!");
}

static const GLenum loadType(ShaderObject::Sources sources) {
  validateSourceCount(sources.size());
  auto type = sources[0]->getType();
  validateSameType(type, sources);
  return type;
}

void ShaderObject::loadSources(Sources sources) const {
  const size_t sourceCount = sources.size();
  const GLchar* sourceCode[sourceCount];

  for (size_t i = 0; i < sourceCount; i++)
    sourceCode[i] = sources[i]->getCode();

  glShaderSource(getID(), sourceCount, sourceCode, nullptr);
}

void ShaderObject::compile() const {
  glCompileShader(getID());
}

void ShaderObject::validateCompileStatus() const {
  if (!compilationSucceeded()) {
    // TODO: Destroy shader here
    throw runtime_error("ShaderObject compilation failed:\n" + getInfoLog());
  }
}

const bool ShaderObject::compilationSucceeded() const {
  return getInt(GL_COMPILE_STATUS) == GL_TRUE;
}

const GLint ShaderObject::getInt(const GLenum parameter) const {
  GLint value;
  glGetShaderiv(getID(), parameter, &value);
  return value;
}

const string ShaderObject::getInfoLog() const {
  vector<GLchar> infoLog(getInt(GL_INFO_LOG_LENGTH));
  glGetShaderInfoLog(getID(), infoLog.size(), nullptr, &infoLog[0]);
  return string(infoLog.begin(), infoLog.end());
}

ShaderObject::ShaderObject(Sources sources)
  : OpenGLData(glCreateShader(loadType(sources))) {
  loadSources(sources);
  compile();
  validateCompileStatus();
}

ShaderObject::~ShaderObject() {
  glDeleteShader(getID());
}

const GLenum ShaderObject::getType() const {
  return getInt(GL_SHADER_TYPE);
}
