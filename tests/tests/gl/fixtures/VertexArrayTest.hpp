#pragma once

#include "OnuxTest.hpp"
#include "gl/VertexBuffer.hpp"
#include "gl/IndexBuffer.hpp"
#include "graphics/Mesh.hpp"

struct VertexArrayTest : OnuxTest {
private:
  const onux::Mesh::Vertexes validVertexData {
    onux::Vertex(),
    onux::Vertex(),
    onux::Vertex(),
  };

  const onux::Mesh::Indexes validIndexData { 0, 1, 2 };

protected:
  const onux::VertexBuffer validVertexBuffer {
    onux::Vertex::LAYOUT,
    validVertexData
  };

  const onux::IndexBuffer validIndexBuffer { validIndexData };
};
