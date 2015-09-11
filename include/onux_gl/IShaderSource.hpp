#pragma once

#include <GL/glew.h>

namespace onux_gl {

struct IShaderSource {
  virtual ~IShaderSource() {}
  virtual const GLenum getType() const = 0;
  virtual const GLchar* getCode() const = 0;
};

} // namespace onux_gl
