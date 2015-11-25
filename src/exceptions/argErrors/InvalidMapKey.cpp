#include "exceptions/argErrors/InvalidMapKey.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"
#include "exceptions/messageBuilders/buildArgInfo.hpp"
#include "exceptions/messageBuilders/buildMustBe.hpp"

using std::string;
using std::vector;

namespace onux {

static const string buildMapKeyMessage(
    const string& parameter,
    const string& function,
    const string& mustBe
) {
    return buildArgMessage(
        parameter,
        function,
        buildArgInfo(mustBe),
        "map key in argument"
    );
}

InvalidMapKey::InvalidMapKey(
    const string&         parameter,
    const string&         function,
    const vector<string>& validKeys
)   : Error(buildMapKeyMessage(
        parameter,
        function,
        buildMustBe(validKeys)
    )) {}

} // namespace onux
