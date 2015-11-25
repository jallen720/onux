#include "exceptions/messageBuilders/buildArgMessage.hpp"

using std::string;

namespace onux {

const string buildArgMessage(
    const string& parameterName,
    const string& functionName,
    const string& argumentInfo,
    const string& argumentDescription
) {
    return "\n  " +
           argumentDescription + " passed to \"" +
           parameterName + "\" parameter for " +
           functionName + "()" +
           argumentInfo;
}

} // namespace onux
