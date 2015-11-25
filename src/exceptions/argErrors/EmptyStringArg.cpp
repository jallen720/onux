#include "exceptions/argErrors/EmptyStringArg.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"

using std::string;

namespace onux {

EmptyStringArg::EmptyStringArg(
    const string& parameterName,
    const string& functionName
)   : Error(buildArgMessage(
        parameterName,
        functionName,
        " cannot be empty",
        "string argument"
    )) {}

} // namespace onux
