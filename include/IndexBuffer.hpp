#pragma once

#include "BufferObject.hpp"

struct IndexBuffer : BufferObject {
  IndexBuffer(
    const GLsizei dataSize,
    const GLuint* data,
    const GLenum  usage
  );
};
