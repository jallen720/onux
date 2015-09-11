#include "onux_gl/BufferObject.hpp"

namespace onux_gl {

static GLuint newBufferObject() {
  GLuint id;
  glGenBuffers(1, &id);
  return id;
}

void BufferObject::loadData() const {
  bind();
  glBufferData(target, dataSize, data, usage);
}

BufferObject::BufferObject(
  const GLenum  target,
  const GLsizei dataSize,
  const GLvoid* data,
  const GLenum  usage
) : OpenGLData(newBufferObject())
  , target(target)
  , dataSize(dataSize)
  , data(data)
  , usage(usage) {}

BufferObject::~BufferObject() {
  glDeleteBuffers(1, &getID());
}

void BufferObject::bind() const {
  glBindBuffer(target, getID());
}

} // namespace onux_gl
