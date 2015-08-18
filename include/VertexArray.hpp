#pragma once

#include "OpenGLData.hpp"

struct VertexBuffer;
struct IndexBuffer;

struct VertexArray : public OpenGLData {
  VertexArray(
    const VertexBuffer& vertexBuffer,
    const IndexBuffer&  indexBuffer
  );

  ~VertexArray();
  void bind() const;
};
