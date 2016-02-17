#include "exceptions/argErrors/InvalidMapValue.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"
#include "exceptions/messageBuilders/buildArgInfo.hpp"
#include "exceptions/messageBuilders/buildMustBe.hpp"

using std::string;
using std::vector;

namespace onux {

static const string buildMapValueMessage(
    const string& parameter,
    const string& function,
    const string& key,
    const string& mustBe
) {
    return buildArgMessage(
        parameter,
        function,
        buildArgInfo(mustBe),
        "map value for \"" + key + "\" key in argument"
    );
}

InvalidMapValue::InvalidMapValue(
    const string&         parameter,
    const string&         function,
    const string&         key,
    const vector<string>& validValues
)   : Error(buildMapValueMessage(
        parameter,
        function,
        key,
        buildMustBe(validValues)
    )) {}

} // namespace onux
