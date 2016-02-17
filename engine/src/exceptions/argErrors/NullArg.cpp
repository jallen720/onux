#include "exceptions/argErrors/NullArg.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"

using std::string;

namespace onux {

NullArg::NullArg(const string& parameter, const string& function)
    : Error(buildArgMessage(
        parameter,
        function,
        " cannot be null"
    )) {}

} // namespace onux
