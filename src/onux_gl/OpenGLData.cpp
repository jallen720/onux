#include "onux_gl/OpenGLData.hpp"

namespace onux_gl {

const GLuint& OpenGLData::getID() const {
  return id;
}

OpenGLData::OpenGLData(const GLuint id)
  : id(id) {}

} // namespace onux_gl
