#include "exceptions/InvalidArg.hpp"

using std::string;
using std::vector;

namespace onux {

static const string createWhat(
  const string& parameterName,
  const string& objectName,
  const string& argument,
  const string& mustBe
) {
  return "\n"
         "  Argument passed to \"" + parameterName + "\" parameter for " + objectName + ":\n"
         "    was: " + argument + "\n"
         "    must be: " + mustBe;
}

static const string getMustBe(const vector<string>& validArguments) {
  string mustBe = "\n";

  for (const string& validArgument : validArguments) {
    mustBe += "      " + validArgument + ",\n";
  }

  return mustBe;
}

InvalidArg::InvalidArg(
  const string& parameterName,
  const string& objectName,
  const string& argument,
  const string& validArgument
) : Error(createWhat(
      parameterName,
      objectName,
      argument,
      validArgument
    )) {}

InvalidArg::InvalidArg(
  const string&         parameterName,
  const string&         objectName,
  const string&         argument,
  const vector<string>& validArguments
) : Error(createWhat(
      parameterName,
      objectName,
      argument,
      getMustBe(validArguments)
    )) {}

} // namespace onux
