#include "exceptions/messageBuilders/buildArgMessage.hpp"

using std::string;

namespace onux {

const string buildArgMessage(
    const string& parameterName,
    const string& objectName,
    const string& argumentInfo,
    const string& argumentDescription
) {
    return "\n  " +
           argumentDescription + " passed to \"" +
           parameterName + "\" parameter for " +
           objectName +
           argumentInfo;
}

} // namespace onux
