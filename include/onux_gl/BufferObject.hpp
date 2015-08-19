#pragma once

#include "onux_gl/OpenGLData.hpp"

namespace onux_gl {
  class BufferObject : OpenGLData {
    const GLenum  target;
    const GLsizei dataSize;
    const GLvoid* data;
    const GLenum  usage;

    void bind() const;

  protected:
    BufferObject(
      const GLenum  target,
      const GLsizei dataSize,
      const GLvoid* data,
      const GLenum  usage
    );

  public:
    ~BufferObject();
    virtual void loadData() const;
  };
}
