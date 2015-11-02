#include "gl/VertexBuffer.hpp"

#include "gl/IBufferData.hpp"
#include "gl/Vertex.hpp"

namespace onux {

VertexBuffer::VertexBuffer(const IBufferData& data, const GLenum usage)
  : BufferObject(
      GL_ARRAY_BUFFER,
      data.getSize(),
      data.getPointer(),
      usage
    ) {}

void VertexBuffer::loadData() const {
  BufferObject::loadData();
  Vertex::attributePointers();
}

} // namespace onux
