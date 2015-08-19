#include "onux_gl/OpenGLData.hpp"

using namespace onux_gl;

OpenGLData::OpenGLData(const GLuint id)
  : id(id) {}

const GLuint& OpenGLData::getID() const {
  return id;
}
