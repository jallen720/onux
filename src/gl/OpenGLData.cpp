#include "gl/OpenGLData.hpp"

namespace onux {

const GLuint& OpenGLData::getID() const {
  return m_id;
}

OpenGLData::OpenGLData(const GLuint id)
  : m_id(id) {}

} // namespace onux
