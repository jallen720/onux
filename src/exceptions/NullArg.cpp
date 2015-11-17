#include "exceptions/NullArg.hpp"

using std::string;

namespace onux {

static const string createWhat(
  const string& parameterName,
  const string& objectName
) {
  return "Argument passed to \"" +
         parameterName + "\" parameter for " +
         objectName + " cannot be null!";
}

NullArg::NullArg(
  const string& parameterName,
  const string& objectName
) : Error(createWhat(parameterName, objectName)) {}

} // namespace onux
