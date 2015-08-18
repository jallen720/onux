#include "IndexBuffer.hpp"

IndexBuffer::IndexBuffer(
  const GLsizei dataSize,
  const GLuint* data,
  const GLenum  usage
) : BufferObject(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, usage) {}
