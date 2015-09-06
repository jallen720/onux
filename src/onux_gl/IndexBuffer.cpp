#include "onux_gl/IndexBuffer.hpp"

namespace onux_gl {
  static const GLsizei size(IndexBuffer::Data data) {
    return sizeof(GLuint) * data.size();
  }

  static const GLvoid* pointer(IndexBuffer::Data data) {
    return &data[0];
  }

  IndexBuffer::IndexBuffer(Data data, const GLenum usage)
    : BufferObject(
        GL_ELEMENT_ARRAY_BUFFER,
        size(data),
        pointer(data),
        usage
      ) {}
}
