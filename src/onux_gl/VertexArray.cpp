#include "onux_gl/VertexArray.hpp"

#include "onux_gl/VertexBuffer.hpp"
#include "onux_gl/IndexBuffer.hpp"

namespace onux_gl {
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
}
