#include "exceptions/subsystemErrors/OpenGlError.hpp"

#include "gl/helpers.hpp"
#include "exceptions/messageBuilders/buildSystemMessage.hpp"

namespace onux {

OpenGlError::OpenGlError(const GLenum error)
  : Error(buildSystemMessage("OPENGL", getErrorMsg(error))) {}

} // namespace onux
