#include "exceptions/subsystemErrors/GLEWError.hpp"

#include "exceptions/messageBuilders/buildSystemMessage.hpp"

using std::string;

namespace onux {

GLEWError::GLEWError(const string& message)
  : Error(buildSystemMessage("GLEW", message)) {}

} // namespace onux
