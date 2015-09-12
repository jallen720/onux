#pragma once

#include "onux_gl/OpenGLData.hpp"

namespace onux_gl {

class BufferObject : OpenGLData {
public:
  virtual void loadData() const;

protected:
  BufferObject(
    const GLenum  target,
    const GLsizei dataSize,
    const GLvoid* data,
    const GLenum  usage
  );
  ~BufferObject();

private:
  const GLenum  m_target;
  const GLsizei m_dataSize;
  const GLvoid* m_data;
  const GLenum  m_usage;

  void bind() const;
};

} // namespace onux_gl
