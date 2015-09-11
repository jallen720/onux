#pragma once

#include <GL/glew.h>

namespace onux_gl {

struct IImage {
  virtual ~IImage() {}
  virtual const GLsizei getWidth() const = 0;
  virtual const GLsizei getHeight() const = 0;
  virtual const GLvoid* getData() const = 0;
};

} // namespace onux_gl
