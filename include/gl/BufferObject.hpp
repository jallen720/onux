#pragma once

#include "gl/OpenGLData.hpp"

namespace onux {

class BufferObject : OpenGLData {
public:
  virtual void loadData() const;

protected:
  BufferObject(
    const GLenum  target,
    const GLsizei size,
    const GLvoid* data,
    const GLenum  usage
  );
  ~BufferObject();

private:
  const GLenum  m_target;
  const GLsizei m_size;
  const GLvoid* m_data;
  const GLenum  m_usage;

  void bind() const;
};

} // namespace onux
