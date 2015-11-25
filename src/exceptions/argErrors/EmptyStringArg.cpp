#include "exceptions/argErrors/EmptyStringArg.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"

using std::string;

namespace onux {

EmptyStringArg::EmptyStringArg(
    const string& parameter,
    const string& function
)   : Error(buildArgMessage(
        parameter,
        function,
        " cannot be empty",
        "string argument"
    )) {}

} // namespace onux
