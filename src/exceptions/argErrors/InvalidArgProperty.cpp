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
  const string& property,
  const string& mustBe
) {
  return buildArgMessage(
    parameterName,
    objectName,
    buildArgInfo(
      property,
      mustBe
    ),
    "Property \"" + propertyName + "\" of argument"
  );
}

InvalidArgProperty::InvalidArgProperty(
  const string& parameterName,
  const string& objectName,
  const string& propertyName,
  const string& property,
  const string& validProperty
) : Error(buildArgPropertyMessage(
      parameterName,
      objectName,
      propertyName,
      property,
      validProperty
    )) {}

InvalidArgProperty::InvalidArgProperty(
  const string&         parameterName,
  const string&         objectName,
  const string&         propertyName,
  const string&         property,
  const vector<string>& validProperties
) : Error(buildArgPropertyMessage(
      parameterName,
      objectName,
      propertyName,
      property,
      buildMustBe(validProperties)
    )) {}

} // namespace onux
