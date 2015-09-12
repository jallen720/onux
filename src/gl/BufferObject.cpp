#include "gl/BufferObject.hpp"

namespace onux {

// BufferObject represents 1 buffer.
static const GLsizei BUFFER_COUNT = 1;

static GLuint newBufferObject() {
  GLuint id;
  glGenBuffers(BUFFER_COUNT, &id);
  return id;
}

void BufferObject::loadData() const {
  bind();
  glBufferData(
    m_target,
    m_dataSize,
    m_data,
    m_usage
  );
}

BufferObject::BufferObject(
  const GLenum  target,
  const GLsizei dataSize,
  const GLvoid* data,
  const GLenum  usage
) : OpenGLData(newBufferObject())
  , m_target(target)
  , m_dataSize(dataSize)
  , m_data(data)
  , m_usage(usage) {}

BufferObject::~BufferObject() {
  glDeleteBuffers(BUFFER_COUNT, &getID());
}

void BufferObject::bind() const {
  glBindBuffer(m_target, getID());
}

} // namespace onux
