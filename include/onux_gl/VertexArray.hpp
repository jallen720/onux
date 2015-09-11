#pragma once

#include "onux_gl/OpenGLData.hpp"

namespace onux_gl {

struct VertexBuffer;
struct IndexBuffer;

struct VertexArray : OpenGLData {
  VertexArray(
    const VertexBuffer& vertexBuffer,
    const IndexBuffer&  indexBuffer
  );
  ~VertexArray();
  void bind() const;
};

} // namespace onux_gl
