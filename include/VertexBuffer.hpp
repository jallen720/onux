#pragma once

#include "BufferObject.hpp"

class Vertex;

struct VertexBuffer : BufferObject {
  VertexBuffer(
    const GLsizei dataSize,
    const Vertex* data,
    const GLenum  usage
  );

  void loadData() const override;
};
