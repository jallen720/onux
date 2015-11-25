#include "exceptions/subsystemErrors/AssimpError.hpp"

#include "exceptions/messageBuilders/buildSystemMessage.hpp"

using std::string;

namespace onux {

AssimpError::AssimpError(const string& message)
    : Error(buildSystemMessage("ASSIMP", message)) {}

} // namespace onux
