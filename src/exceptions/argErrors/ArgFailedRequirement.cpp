#include "exceptions/argErrors/ArgFailedRequirement.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"

using std::string;

namespace onux {

ArgFailedRequirement::ArgFailedRequirement(
    const string& parameter,
    const string& function,
    const string& requirement
)   : Error(buildArgMessage(
        parameter,
        function,
        " failed requirement:\n    " + requirement
    )) {}

} // namespace onux
