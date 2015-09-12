#pragma once

#include "onux_gl/VertexBuffer.hpp"
#include "onux_gl/IndexBuffer.hpp"
#include "onux_gl/VertexArray.hpp"

class Mesh;

class MeshRenderer {
public:
  MeshRenderer(const Mesh& mesh);
  void render() const;

private:
  const Mesh&                 m_mesh;
  const onux_gl::VertexBuffer m_vertexBuffer;
  const onux_gl::IndexBuffer  m_indexBuffer;
  const onux_gl::VertexArray  m_vertexArray;
};
