#include "gl/ShaderObject.hpp"

#include <string>
#include <stdexcept>

#include "gl/interfaces/IShaderSource.hpp"
#include "utils/existsIn.hpp"
#include "exceptions/ArgFailedRequirement.hpp"
#include "exceptions/InvalidArgProperty.hpp"

using std::vector;
using std::string;
using std::to_string;
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

static void validateSourceCount(const size_t sourceCount) {
  static const size_t MIN_SOURCE_COUNT = 1;

  if (sourceCount < MIN_SOURCE_COUNT) {
    throw InvalidArgProperty(
      "sources",
      "ShaderObject",
      "count",
      to_string(sourceCount),
      ">= " + to_string(MIN_SOURCE_COUNT)
    );
  }
}

static bool areSameType(ShaderObject::Sources sources, const GLenum type) {
  return !existsIn(sources, [&](auto source) {
    return source->getType() != type;
  });
}

static void validateSameType(ShaderObject::Sources sources, const GLenum type) {
  if (!areSameType(sources, type)) {
    throw ArgFailedRequirement(
      "sources",
      "ShaderObject",
      "All sources must be the same type"
    );
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
