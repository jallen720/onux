#pragma once

#include "gl/BufferObject.hpp"

namespace onux {

struct IBufferData;

class VertexBuffer : public BufferObject {
public:
  VertexBuffer(const IBufferData& data, const GLenum usage = GL_STATIC_DRAW);
  void loadData() const override;
};

} // namespace onux
