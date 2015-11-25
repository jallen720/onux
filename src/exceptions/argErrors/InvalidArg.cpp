#include "exceptions/argErrors/InvalidArg.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"
#include "exceptions/messageBuilders/buildArgInfo.hpp"
#include "exceptions/messageBuilders/buildMustBe.hpp"

using std::string;
using std::vector;

namespace onux {

static const string buildInvalidArgMessage(
    const string& parameter,
    const string& function,
    const string& mustBe
) {
    return buildArgMessage(
        parameter,
        function,
        buildArgInfo(mustBe)
    );
}

InvalidArg::InvalidArg(
    const string& parameter,
    const string& function,
    const string& validArgument
)   : Error(buildInvalidArgMessage(
        parameter,
        function,
        validArgument
    )) {}

InvalidArg::InvalidArg(
    const string&         parameter,
    const string&         function,
    const vector<string>& validArguments
)   : Error(buildInvalidArgMessage(
        parameter,
        function,
        buildMustBe(validArguments)
    )) {}

} // namespace onux
