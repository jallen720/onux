#pragma once

#include <memory>

#include "gl/OpenGLData.hpp"

namespace onux {

class BufferObject : OpenGLData {
public:
  virtual void loadData() const;

protected:
  BufferObject(
    const GLenum     target,
    const GLsizeiptr size,
    const GLvoid*    data,
    const GLenum     usage
  );
  ~BufferObject();

private:
  struct Impl;
  std::unique_ptr<Impl> impl;
};

} // namespace onux
