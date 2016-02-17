#include "exceptions/messageBuilders/buildArgMessage.hpp"

using std::string;

namespace onux {

const string buildArgMessage(
    const string& parameter,
    const string& function,
    const string& argInfo,
    const string& argDescription
) {
    return "\n  " +
           argDescription + " passed to \"" +
           parameter + "\" parameter for " +
           function + "()" +
           argInfo;
}

} // namespace onux
