#pragma once

#include "OnuxTest.hpp"
#include "onux_gl/VertexBuffer.hpp"
#include "onux_gl/IndexBuffer.hpp"
#include "onux_gl/Vertex.hpp"

struct VertexArrayTest : OnuxTest {
private:
  const std::vector<onux_gl::Vertex> validVertexData {
    onux_gl::Vertex(),
    onux_gl::Vertex(),
    onux_gl::Vertex(),
  };

  const std::vector<GLuint> validIndexData { 0, 1, 2 };

protected:
  const onux_gl::VertexBuffer validVertexBuffer { validVertexData };
  const onux_gl::IndexBuffer  validIndexBuffer  { validIndexData  };
};
