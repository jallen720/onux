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
  const Mesh& mesh;
  const onux_gl::VertexBuffer vertexBuffer;
  const onux_gl::IndexBuffer indexBuffer;
  const onux_gl::VertexArray vertexArray;
};
