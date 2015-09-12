#pragma once

#include "gl/VertexBuffer.hpp"
#include "gl/IndexBuffer.hpp"
#include "gl/VertexArray.hpp"

class Mesh;

class MeshRenderer {
public:
  MeshRenderer(const Mesh& mesh);
  void render() const;

private:
  const Mesh&                 m_mesh;
  const onux::VertexBuffer m_vertexBuffer;
  const onux::IndexBuffer  m_indexBuffer;
  const onux::VertexArray  m_vertexArray;
};
