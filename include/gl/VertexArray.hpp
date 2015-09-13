#pragma once

#include "gl/OpenGLData.hpp"

namespace onux {

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

} // namespace onux