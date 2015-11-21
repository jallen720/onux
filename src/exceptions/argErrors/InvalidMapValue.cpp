#include "exceptions/argErrors/InvalidMapValue.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"
#include "exceptions/messageBuilders/buildArgInfo.hpp"
#include "exceptions/messageBuilders/buildMustBe.hpp"

using std::string;
using std::vector;

namespace onux {

static const string buildMapValueMessage(
  const string& parameterName,
  const string& objectName,
  const string& key,
  const string& value,
  const string& mustBe
) {
  return buildArgMessage(
    parameterName,
    objectName,
    buildArgInfo(
      value,
      mustBe
    ),
    "Map value for \"" + key + "\" key in argument"
  );
}

InvalidMapValue::InvalidMapValue(
  const string&         parameterName,
  const string&         objectName,
  const string&         key,
  const string&         value,
  const vector<string>& validValues
) : Error(buildMapValueMessage(
      parameterName,
      objectName,
      key,
      value,
      buildMustBe(validValues)
    )) {}

} // namespace onux
