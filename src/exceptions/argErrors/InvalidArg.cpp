#include "exceptions/argErrors/InvalidArg.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"
#include "exceptions/messageBuilders/buildArgInfo.hpp"
#include "exceptions/messageBuilders/buildMustBe.hpp"

using std::string;
using std::vector;

namespace onux {

static const string buildInvalidArgMessage(
    const string& parameterName,
    const string& functionName,
    const string& mustBe
) {
    return buildArgMessage(
        parameterName,
        functionName,
        buildArgInfo(mustBe)
    );
}

InvalidArg::InvalidArg(
    const string& parameterName,
    const string& functionName,
    const string& validArgument
)   : Error(buildInvalidArgMessage(
        parameterName,
        functionName,
        validArgument
    )) {}

InvalidArg::InvalidArg(
    const string&         parameterName,
    const string&         functionName,
    const vector<string>& validArguments
)   : Error(buildInvalidArgMessage(
        parameterName,
        functionName,
        buildMustBe(validArguments)
    )) {}

} // namespace onux
