#include "onux_gl/VertexBuffer.hpp"

#include "onux_gl/Vertex.hpp"

namespace onux_gl {
  static const GLsizei size(VertexBuffer::Data data) {
    return sizeof(Vertex) * data.size();
  }

  static const GLvoid* pointer(VertexBuffer::Data data) {
    return &data[0];
  }

  VertexBuffer::VertexBuffer(Data data, const GLenum usage)
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
}
