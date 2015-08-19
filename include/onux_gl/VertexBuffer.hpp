#pragma once

#include "onux_gl/BufferObject.hpp"

namespace onux_gl {
  class Vertex;

  struct VertexBuffer : BufferObject {
    VertexBuffer(
      const GLsizei dataSize,
      const Vertex* data,
      const GLenum  usage
    );

    void loadData() const override;
  };
}
