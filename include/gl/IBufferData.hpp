#pragma once

#include <GL/glew.h>

namespace onux {

struct IBufferData {
  virtual ~IBufferData() {}
  virtual const GLsizei getSize() const = 0;
  virtual const GLvoid* getPointer() const = 0;
};

} // namespace onux
