#include "exceptions/argErrors/InvalidMapKey.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"
#include "exceptions/messageBuilders/buildArgInfo.hpp"
#include "exceptions/messageBuilders/buildMustBe.hpp"

using std::string;
using std::vector;

namespace onux {

static const string buildMapKeyMessage(
    const string& parameterName,
    const string& functionName,
    const string& mustBe
) {
    return buildArgMessage(
        parameterName,
        functionName,
        buildArgInfo(mustBe),
        "map key in argument"
    );
}

InvalidMapKey::InvalidMapKey(
    const string&         parameterName,
    const string&         functionName,
    const vector<string>& validKeys
)   : Error(buildMapKeyMessage(
        parameterName,
        functionName,
        buildMustBe(validKeys)
    )) {}

} // namespace onux
