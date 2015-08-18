#pragma once

#include "OpenGLData.hpp"

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
