#include "gl/VertexArray.hpp"

#include "gl/VertexBuffer.hpp"
#include "gl/IndexBuffer.hpp"

namespace onux {

static GLuint newVertexArray() {
  GLuint id;
  glGenVertexArrays(1, &id);
  return id;
}

VertexArray::VertexArray(
  const VertexBuffer& vertexBuffer,
  const IndexBuffer&  indexBuffer
) : OpenGLData(newVertexArray()) {
  bind();
  vertexBuffer.loadData();
  indexBuffer.loadData();
}

VertexArray::~VertexArray() {
  glDeleteVertexArrays(1, &getID());
}

void VertexArray::bind() const {
  glBindVertexArray(getID());
}

} // namespace onux
