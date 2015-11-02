#pragma once

#include <vector>

#include "gl/BufferObject.hpp"

namespace onux {

class IndexBuffer : public BufferObject {
public:
  typedef std::vector<GLuint> Data;

  IndexBuffer(const Data& data, const GLenum usage = GL_STATIC_DRAW);
};

} // namespace onux
