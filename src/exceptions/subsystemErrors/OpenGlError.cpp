#include "exceptions/subsystemErrors/OpenGlError.hpp"

#include "gl/utils/getErrorMessage.hpp"
#include "exceptions/messageBuilders/buildSystemMessage.hpp"

namespace onux {

OpenGlError::OpenGlError(const GLenum error)
  : Error(buildSystemMessage("OPENGL", getErrorMessage(error))) {}

} // namespace onux
