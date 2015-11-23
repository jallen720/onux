#include "exceptions/argErrors/InvalidArgProperty.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"
#include "exceptions/messageBuilders/buildArgInfo.hpp"
#include "exceptions/messageBuilders/buildMustBe.hpp"

using std::string;
using std::vector;

namespace onux {

static const string buildArgPropertyMessage(
  const string& parameterName,
  const string& objectName,
  const string& propertyName,
  const string& mustBe
) {
  return buildArgMessage(
    parameterName,
    objectName,
    buildArgInfo(mustBe),
    "property \"" + propertyName + "\" of argument"
  );
}

InvalidArgProperty::InvalidArgProperty(
  const string& parameterName,
  const string& objectName,
  const string& propertyName,
  const string& validProperty
) : Error(buildArgPropertyMessage(
      parameterName,
      objectName,
      propertyName,
      validProperty
    )) {}

InvalidArgProperty::InvalidArgProperty(
  const string&         parameterName,
  const string&         objectName,
  const string&         propertyName,
  const vector<string>& validProperties
) : Error(buildArgPropertyMessage(
      parameterName,
      objectName,
      propertyName,
      buildMustBe(validProperties)
    )) {}

} // namespace onux
