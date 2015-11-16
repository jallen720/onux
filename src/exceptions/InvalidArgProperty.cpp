#include "exceptions/InvalidArgProperty.hpp"

using std::string;
using std::vector;

namespace onux {

static const string createWhat(
  const string& parameterName,
  const string& objectName,
  const string& propertyName,
  const string& property,
  const string& mustBe
) {
  return "\n"
         "  Property \"" + propertyName + "\" of argument passed to \"" + parameterName + "\" parameter for " + objectName + ":\n"
         "    was: " + property + "\n"
         "    must be: " + mustBe;
}

static const string getMustBe(const vector<string>& validProperties) {
  string mustBe = "\n";

  for (const string& validProperty : validProperties) {
    mustBe += "      " + validProperty + ",\n";
  }

  return mustBe;
}

InvalidArgProperty::InvalidArgProperty(
  const string&         parameterName,
  const string&         objectName,
  const string&         propertyName,
  const string&         property,
  const vector<string>& validProperties
) : Exception(createWhat(
      parameterName,
      objectName,
      propertyName,
      property,
      getMustBe(validProperties)
    )) {}

} // namespace onux
