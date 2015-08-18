#include "VertexArray.hpp"

#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "loggers.hpp"

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
  logCreation(this, "VertexArray");
}

VertexArray::~VertexArray() {
  logDestruction(this, "VertexArray");
  glDeleteVertexArrays(1, &getID());
}

void VertexArray::bind() const {
  glBindVertexArray(getID());
}
