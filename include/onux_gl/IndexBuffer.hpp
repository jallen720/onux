#pragma once

#include <vector>

#include "onux_gl/BufferObject.hpp"

namespace onux_gl {
  using std::vector;

  struct IndexBuffer : BufferObject {
    typedef const vector<GLuint>& Data;

    IndexBuffer(Data data, const GLenum usage = GL_STATIC_DRAW);
  };
}
