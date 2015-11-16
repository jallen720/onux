#include "exceptions/InvalidMapValue.hpp"

using std::string;
using std::vector;

namespace onux {

static const string createWhat(
  const string& parameterName,
  const string& objectName,
  const string& key,
  const string& value,
  const string& mustBe
) {
  return "\n"
         "  Map value for \"" + key + "\" key in argument passed to \"" + parameterName + "\" parameter for " + objectName + ":\n"
         "    was: " + value + "\n"
         "    must be: " + mustBe;
}

static const string getMustBe(const vector<string>& validValues) {
  string mustBe = "\n";

  for (const string& validValue : validValues) {
    mustBe += "      " + validValue + ",\n";
  }

  return mustBe;
}

InvalidMapValue::InvalidMapValue(
  const string&         parameterName,
  const string&         objectName,
  const string&         key,
  const string&         value,
  const vector<string>& validValues
) : Exception(createWhat(
      parameterName,
      objectName,
      key,
      value,
      getMustBe(validValues)
    )) {}

} // namespace onux
