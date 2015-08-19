#pragma once

#include "onux_gl/BufferObject.hpp"

namespace onux_gl {
  struct IndexBuffer : BufferObject {
    IndexBuffer(
      const GLsizei dataSize,
      const GLuint* data,
      const GLenum  usage
    );
  };
}
