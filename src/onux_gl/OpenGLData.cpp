#include "onux_gl/OpenGLData.hpp"

namespace onux_gl {

const GLuint& OpenGLData::getID() const {
  return m_id;
}

OpenGLData::OpenGLData(const GLuint id)
  : m_id(id) {}

} // namespace onux_gl
