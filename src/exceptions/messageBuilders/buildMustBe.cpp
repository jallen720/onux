#include "exceptions/messageBuilders/buildMustBe.hpp"

using std::string;
using std::vector;

namespace onux {

const string buildMustBe(const vector<string>& validArguments) {
  string mustBe = "\n";

  for (const string& validArgument : validArguments) {
    mustBe += "      " + validArgument + ",\n";
  }

  return mustBe;
}

} // namespace onux
