#include "exceptions/argErrors/InvalidArgProperty.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"
#include "exceptions/messageBuilders/buildArgInfo.hpp"
#include "exceptions/messageBuilders/buildMustBe.hpp"

using std::string;
using std::vector;

namespace onux {

static const string buildArgPropertyMessage(
    const string& parameter,
    const string& function,
    const string& property,
    const string& mustBe
) {
    return buildArgMessage(
        parameter,
        function,
        buildArgInfo(mustBe),
        "property \"" + property + "\" of argument"
    );
}

InvalidArgProperty::InvalidArgProperty(
    const string& parameter,
    const string& function,
    const string& property,
    const string& validProperty
)   : Error(buildArgPropertyMessage(
        parameter,
        function,
        property,
        validProperty
    )) {}

InvalidArgProperty::InvalidArgProperty(
    const string&         parameter,
    const string&         function,
    const string&         property,
    const vector<string>& validProperties
)   : Error(buildArgPropertyMessage(
        parameter,
        function,
        property,
        buildMustBe(validProperties)
    )) {}

} // namespace onux
