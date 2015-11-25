#include "exceptions/argErrors/NullArg.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"

using std::string;

namespace onux {

NullArg::NullArg(
    const string& parameterName,
    const string& functionName
)   : Error(buildArgMessage(
        parameterName,
        functionName,
        " cannot be null"
    )) {}

} // namespace onux
