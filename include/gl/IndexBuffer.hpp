#pragma once

#include "gl/BufferObject.hpp"

namespace onux {

struct IBufferData;

class IndexBuffer : public BufferObject {
public:
  IndexBuffer(const IBufferData& data, const GLenum usage = GL_STATIC_DRAW);
};

} // namespace onux
