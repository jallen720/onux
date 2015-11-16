#include "exceptions/InvalidMapKey.hpp"

using std::string;
using std::vector;

namespace onux {

static const string createWhat(
  const string& parameterName,
  const string& objectName,
  const string& key,
  const string& mustBe
) {
  return "\n"
         "  Map key in argument passed to \"" + parameterName + "\" parameter for " + objectName + ":\n"
         "    was: " + key + "\n"
         "    must be: " + mustBe;
}

static const string getMustBe(const vector<string>& validKeys) {
  string mustBe = "\n";

  for (const string& validKey : validKeys) {
    mustBe += "      " + validKey + ",\n";
  }

  return mustBe;
}

InvalidMapKey::InvalidMapKey(
  const string&         parameterName,
  const string&         objectName,
  const string&         key,
  const vector<string>& validKeys
) : Exception(createWhat(
      parameterName,
      objectName,
      key,
      getMustBe(validKeys)
    )) {}

} // namespace onux
