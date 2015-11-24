#include "gl/VertexArray.hpp"

#include "gl/VertexBuffer.hpp"
#include "gl/IndexBuffer.hpp"

namespace onux {

// VertexArray represents 1 vertex array.
static const GLsizei VERTEX_ARRAY_COUNT = 1;

static GLuint createVertexArray() {
  GLuint id;
  glGenVertexArrays(VERTEX_ARRAY_COUNT, &id);
  return id;
}

VertexArray::VertexArray(
  const VertexBuffer& vertexBuffer,
  const IndexBuffer&  indexBuffer
) : GLData(createVertexArray()) {
  bind();
  vertexBuffer.loadData();
  indexBuffer.loadData();
}

VertexArray::~VertexArray() {
  glDeleteVertexArrays(VERTEX_ARRAY_COUNT, &getID());
}

void VertexArray::bind() const {
  glBindVertexArray(getID());
}

} // namespace onux
