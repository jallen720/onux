#pragma once

#include <vector>

#include "onux_gl/BufferObject.hpp"

namespace onux_gl {
  using std::vector;

  class Vertex;

  struct VertexBuffer : BufferObject {
    typedef const vector<Vertex>& Data;

    VertexBuffer(Data data, const GLenum usage = GL_STATIC_DRAW);
    void loadData() const override;
  };
}
