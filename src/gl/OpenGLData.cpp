#include "gl/OpenGLData.hpp"

namespace onux {

struct OpenGLData::Impl {
  const GLuint id;

  Impl(const GLuint id);
};

const GLuint& OpenGLData::getID() const {
  return impl->id;
}

OpenGLData::OpenGLData(const GLuint id)
  : impl(new Impl(id)) {}

// Implementation

OpenGLData::Impl::Impl(const GLuint id)
  : id(id) {}

} // namespace onux
