#include "exceptions/messageBuilders/buildSystemMessage.hpp"

using std::string;

namespace onux {

const string buildSystemMessage(
  const string& systemName,
  const string& message
) {
  return systemName + " ERROR: " + message;
}

} // namespace onux
