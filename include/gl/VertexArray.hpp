#pragma once

#include "gl/GLData.hpp"

namespace onux {

struct VertexBuffer;
struct IndexBuffer;

class VertexArray : public GLData {
public:
  VertexArray(
    const VertexBuffer& vertexBuffer,
    const IndexBuffer&  indexBuffer
  );
  ~VertexArray();
  void bind() const;
};

} // namespace onux
