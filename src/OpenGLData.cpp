#include "OpenGLData.hpp"

OpenGLData::OpenGLData(const GLuint id)
  : id(id) {}

const GLuint& OpenGLData::getID() const {
  return id;
}
