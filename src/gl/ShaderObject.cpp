#include "gl/ShaderObject.hpp"

#include <stdexcept>

#include "gl/IShaderSource.hpp"

using std::vector;
using std::string;
using std::runtime_error;

namespace onux {

static const bool isValidSourceCount(const size_t sourceCount) {
  static const size_t MIN_SOURCE_COUNT = 1;
  return sourceCount >= MIN_SOURCE_COUNT;
}

static void validateSourceCount(const size_t sourceCount) {
  if (!isValidSourceCount(sourceCount)) {
    throw runtime_error("ShaderObject requires atleast 1 ShaderSource!");
  }
}

static void validateSameType(const ShaderObject::Sources& sources, const GLenum type) {
  for (auto source : sources) {
    if (source->getType() != type) {
      throw runtime_error(
        "All ShaderSource files for ShaderObject must have the same type!"
      );
    }
  }
}

static const GLenum loadType(const ShaderObject::Sources& sources) {
  validateSourceCount(sources.size());
  const GLenum type = sources[0]->getType();
  validateSameType(sources, type);
  return type;
}

ShaderObject::ShaderObject(const Sources& sources)
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

void ShaderObject::loadSources(const Sources& sources) const {
  const size_t sourceCount = sources.size();
  const GLchar* sourceCode[sourceCount];

  for (size_t i = 0; i < sourceCount; i++) {
    sourceCode[i] = sources[i]->getCode();
  }

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

  glGetShaderInfoLog(
    getID(),
    infoLog.size(),
    nullptr,
    &infoLog[0]
  );

  return string(infoLog.begin(), infoLog.end());
}

} // namespace onux
