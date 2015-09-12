#pragma once

#include "OnuxTest.hpp"
#include "gl/VertexBuffer.hpp"
#include "gl/IndexBuffer.hpp"
#include "gl/Vertex.hpp"

struct VertexArrayTest : OnuxTest {
private:
  const std::vector<onux::Vertex> validVertexData {
    onux::Vertex(),
    onux::Vertex(),
    onux::Vertex(),
  };

  const std::vector<GLuint> validIndexData { 0, 1, 2 };

protected:
  const onux::VertexBuffer validVertexBuffer { validVertexData };
  const onux::IndexBuffer  validIndexBuffer  { validIndexData  };
};
