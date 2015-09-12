#include "gl/VertexBuffer.hpp"

#include "gl/Vertex.hpp"

namespace onux {

static const GLsizei size(const VertexBuffer::Data& data) {
  return sizeof(Vertex) * data.size();
}

static const GLvoid* pointer(const VertexBuffer::Data& data) {
  return &data[0];
}

VertexBuffer::VertexBuffer(const Data& data, const GLenum usage)
  : BufferObject(
      GL_ARRAY_BUFFER,
      size(data),
      pointer(data),
      usage
    ) {}

void VertexBuffer::loadData() const {
  BufferObject::loadData();
  Vertex::attributePointers();
}

} // namespace onux
