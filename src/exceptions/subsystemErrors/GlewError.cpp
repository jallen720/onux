#include "exceptions/subsystemErrors/GlewError.hpp"

#include "exceptions/messageBuilders/buildSystemMessage.hpp"

using std::string;

namespace onux {

GlewError::GlewError(const string& message)
  : Error(buildSystemMessage("GLEW", message)) {}

} // namespace onux
