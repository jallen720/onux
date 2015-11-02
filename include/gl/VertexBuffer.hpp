#pragma once

#include <vector>

#include "gl/BufferObject.hpp"

namespace onux {

class Vertex;

class VertexBuffer : public BufferObject {
public:
  typedef std::vector<Vertex> Data;

  VertexBuffer(const Data& data, const GLenum usage = GL_STATIC_DRAW);
  void loadData() const override;
};

} // namespace onux
