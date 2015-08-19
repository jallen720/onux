#include "onux_gl/IndexBuffer.hpp"

using namespace onux_gl;

IndexBuffer::IndexBuffer(
  const GLsizei dataSize,
  const GLuint* data,
  const GLenum  usage
) : BufferObject(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, usage) {}
