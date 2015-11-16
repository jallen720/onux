#include "exceptions/NullArg.hpp"

using std::string;

namespace onux {

static const string createWhat(
  const string& parameterName,
  const string& objectName
) {
  return "Argument passed to \"" +
         parameterName + "\" parameter for " +
         objectName + " was null!";
}

NullArg::NullArg(
  const string& parameterName,
  const string& objectName
) : Exception(createWhat(parameterName, objectName)) {}

} // namespace onux
