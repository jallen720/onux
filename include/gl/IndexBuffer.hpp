#pragma once

#include <vector>

#include "gl/BufferObject.hpp"

namespace onux {

struct IndexBuffer : BufferObject {
  typedef std::vector<GLuint> Data;

  IndexBuffer(const Data& data, const GLenum usage = GL_STATIC_DRAW);
};

} // namespace onux
