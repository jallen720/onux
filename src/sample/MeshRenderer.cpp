#include "sample/MeshRenderer.hpp"

#include "Mesh.hpp"

MeshRenderer::MeshRenderer(const Mesh& mesh)
  : mesh(mesh)
  , vertexBuffer(mesh.getVertexes())
  , indexBuffer(mesh.getIndexes())
  , vertexArray(vertexBuffer, indexBuffer) {}

static void drawElements(const GLsizei indexCount) {
  static const GLenum  MODE  = GL_TRIANGLES;
  static const GLenum  TYPE  = GL_UNSIGNED_INT;
  static const GLvoid* FIRST = 0;
  glDrawElements(MODE, indexCount, TYPE, FIRST);
}

void MeshRenderer::render() const {
  vertexArray.bind();
  drawElements(mesh.getIndexes().size());
}
