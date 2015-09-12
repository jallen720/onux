#include "gl/IndexBuffer.hpp"

namespace onux {

static const GLsizei size(const IndexBuffer::Data& data) {
  return sizeof(GLuint) * data.size();
}

static const GLvoid* pointer(const IndexBuffer::Data& data) {
  return &data[0];
}

IndexBuffer::IndexBuffer(const Data& data, const GLenum usage)
  : BufferObject(
      GL_ELEMENT_ARRAY_BUFFER,
      size(data),
      pointer(data),
      usage
    ) {}

} // namespace onux
