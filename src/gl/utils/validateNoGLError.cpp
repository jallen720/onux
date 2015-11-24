#include "gl/utils/validateNoGLError.hpp"

#include <GL/glew.h>

#include "exceptions/subsystemErrors/OpenGlError.hpp"

namespace onux {

void validateNoGLError() {
  const GLenum error = glGetError();

  if (error != GL_NO_ERROR) {
    throw OpenGlError(error);
  }
}

} // namespace onux
