#include "BufferObject.hpp"

static GLuint newBufferObject() {
  GLuint id;
  glGenBuffers(1, &id);
  return id;
}

void BufferObject::bind() const {
  glBindBuffer(target, getID());
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

void BufferObject::loadData() const {
  bind();
  glBufferData(target, dataSize, data, usage);
}
