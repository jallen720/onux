#include "VertexBuffer.hpp"

#include "Vertex.hpp"

VertexBuffer::VertexBuffer(
  const GLsizei dataSize,
  const Vertex* data,
  const GLenum  usage
) : BufferObject(GL_ARRAY_BUFFER, dataSize, data, usage) {}

void VertexBuffer::loadData() const {
  BufferObject::loadData();
  Vertex::attributePointers();
}
