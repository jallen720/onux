#include "exceptions/subsystemErrors/GLError.hpp"

#include "gl/utils/getErrorMessage.hpp"
#include "exceptions/messageBuilders/buildSystemMessage.hpp"

namespace onux {

GLError::GLError(const GLenum error)
    : Error(buildSystemMessage("OPENGL", getErrorMessage(error))) {}

} // namespace onux
