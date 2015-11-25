#include "exceptions/argErrors/ArgFailedRequirement.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"

using std::string;

namespace onux {

ArgFailedRequirement::ArgFailedRequirement(
    const string& parameterName,
    const string& functionName,
    const string& requirement
)   : Error(buildArgMessage(
        parameterName,
        functionName,
        " failed requirement:\n    " + requirement
    )) {}

} // namespace onux
