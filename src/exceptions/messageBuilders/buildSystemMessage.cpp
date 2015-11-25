#include "exceptions/messageBuilders/buildSystemMessage.hpp"

using std::string;

namespace onux {

const string buildSystemMessage(const string& system, const string& message) {
    return system + " ERROR: " + message;
}

} // namespace onux
