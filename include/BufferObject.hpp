#pragma once

#include "OpenGLData.hpp"

// TODO: Inherit privately
class BufferObject : public OpenGLData {
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
