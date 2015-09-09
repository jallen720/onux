#pragma once

#include "OnuxTest.hpp"
#include "onux_gl/VertexBuffer.hpp"
#include "onux_gl/IndexBuffer.hpp"
#include "onux_gl/Vertex.hpp"

using std::vector;
using onux_gl::VertexBuffer;
using onux_gl::IndexBuffer;
using onux_gl::Vertex;

class VertexArrayTest : public OnuxTest {
  const vector<Vertex> validVertexData {
    Vertex(),
    Vertex(),
    Vertex(),
  };

  const vector<GLuint> validIndexData { 0, 1, 2 };

public:
  const VertexBuffer validVertexBuffer { validVertexData };
  const IndexBuffer  validIndexBuffer  { validIndexData  };
};
