#include "gl/ShaderObject.hpp"

#include <string>
#include <stdexcept>

#include "gl/interfaces/IShaderSource.hpp"

using std::vector;
using std::string;
using std::runtime_error;

namespace onux {

struct ShaderObject::Impl {
  const ShaderObject* self;

  Impl(const ShaderObject* self);
  void loadSources(Sources sources) const;
  void compile() const;
  void validateCompileStatus() const;
  const bool compilationSucceeded() const;
  const GLint getInt(const GLenum parameter) const;
  const string getInfoLog() const;
};

static const bool isValidSourceCount(const size_t sourceCount) {
  static const size_t MIN_SOURCE_COUNT = 1;
  return sourceCount >= MIN_SOURCE_COUNT;
}

static void validateSourceCount(const size_t sourceCount) {
  if (!isValidSourceCount(sourceCount)) {
    throw runtime_error("ShaderObject requires atleast 1 ShaderSource!");
  }
}

static void validateSameType(ShaderObject::Sources sources, const GLenum type) {
  for (auto source : sources) {
    if (source->getType() != type) {
      throw runtime_error("All ShaderSource files for ShaderObject must have the same type!");
    }
  }
}

static const GLenum loadType(ShaderObject::Sources sources, const GLenum type) {
  validateSameType(sources, type);
  return type;
}

static const GLuint loadShaderObject(ShaderObject::Sources sources) {
  validateSourceCount(sources.size());
  return glCreateShader(loadType(sources, sources[0]->getType()));
}

ShaderObject::ShaderObject(Sources sources)
  : OpenGLData(loadShaderObject(sources))
  , impl(new Impl(this)) {
  impl->loadSources(sources);
  impl->compile();
  impl->validateCompileStatus();
}

ShaderObject::~ShaderObject() {
  glDeleteShader(getID());
}

const GLenum ShaderObject::getType() const {
  return impl->getInt(GL_SHADER_TYPE);
}

// Implementation

ShaderObject::Impl::Impl(const ShaderObject* self)
  : self(self) {}

void ShaderObject::Impl::loadSources(Sources sources) const {
  const size_t sourceCount = sources.size();
  const GLchar* sourceCode[sourceCount];

  for (size_t i = 0; i < sourceCount; i++) {
    sourceCode[i] = sources[i]->getCode();
  }

  glShaderSource(
    self->getID(),
    sourceCount,
    sourceCode,
    nullptr
  );
}

void ShaderObject::Impl::compile() const {
  glCompileShader(self->getID());
}

void ShaderObject::Impl::validateCompileStatus() const {
  if (!compilationSucceeded()) {
    // TODO: Destroy shader here
    throw runtime_error("ShaderObject compilation failed:\n" + getInfoLog());
  }
}

const bool ShaderObject::Impl::compilationSucceeded() const {
  return getInt(GL_COMPILE_STATUS) == GL_TRUE;
}

const GLint ShaderObject::Impl::getInt(const GLenum parameter) const {
  GLint value;
  glGetShaderiv(self->getID(), parameter, &value);
  return value;
}

const string ShaderObject::Impl::getInfoLog() const {
  vector<GLchar> infoLog(getInt(GL_INFO_LOG_LENGTH));

  glGetShaderInfoLog(
    self->getID(),
    infoLog.size(),
    nullptr,
    &infoLog[0]
  );

  return string(infoLog.begin(), infoLog.end());
}

} // namespace onux
