#pragma once

#include <vector>

#include "onux_gl/BufferObject.hpp"

namespace onux_gl {

struct IndexBuffer : BufferObject {
  typedef std::vector<GLuint> Data;

  IndexBuffer(const Data& data, const GLenum usage = GL_STATIC_DRAW);
};

} // namespace onux_gl
