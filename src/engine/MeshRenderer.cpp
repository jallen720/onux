#include "engine/MeshRenderer.hpp"

#include "graphics/Mesh.hpp"
#include "graphics/Vertex.hpp"

namespace onux {

MeshRenderer::MeshRenderer(const Mesh& mesh)
  : m_mesh(mesh)
  , m_vertexBuffer(Vertex::LAYOUT, m_mesh.getVertexes())
  , m_indexBuffer(m_mesh.getIndexes())
  , m_vertexArray(m_vertexBuffer, m_indexBuffer) {}

static void drawElements(const GLsizei indexCount) {
  static const GLenum  MODE  = GL_TRIANGLES;
  static const GLenum  TYPE  = GL_UNSIGNED_INT;
  static const GLvoid* FIRST = 0;
  glDrawElements(MODE, indexCount, TYPE, FIRST);
}

void MeshRenderer::render() const {
  m_vertexArray.bind();
  drawElements(m_mesh.getIndexes().getCount());
}

} // namespace onux
