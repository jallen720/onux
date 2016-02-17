#include "exceptions/Error.hpp"

#include "exceptions/messageBuilders/buildSystemMessage.hpp"

using std::runtime_error;
using std::string;

namespace onux {

Error::Error(const string& message)
    : runtime_error(buildSystemMessage("ONUX", message)) {}

} // namespace onux
