#include "exceptions/validators/validateNoGLError.hpp"

#include <GL/glew.h>

#include "exceptions/subsystemErrors/GLError.hpp"

namespace onux {

void validateNoGLError() {
    const GLenum error = glGetError();

    if (error != GL_NO_ERROR) {
        throw GLError(error);
    }
}

} // namespace onux
