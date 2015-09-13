#pragma once

#include "gl/VertexBuffer.hpp"
#include "gl/IndexBuffer.hpp"
#include "gl/VertexArray.hpp"

namespace onux {

class Mesh;

class MeshRenderer {
public:
  MeshRenderer(const Mesh& mesh);
  void render() const;

private:
  const Mesh&        m_mesh;
  const VertexBuffer m_vertexBuffer;
  const IndexBuffer  m_indexBuffer;
  const VertexArray  m_vertexArray;
};

} // namespace onux
