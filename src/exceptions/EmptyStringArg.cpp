#include "exceptions/EmptyStringArg.hpp"

using std::string;

namespace onux {

static const string createWhat(
  const string& parameterName,
  const string& objectName
) {
  return "String argument passed to \"" +
         parameterName + "\" parameter for " +
         objectName + " cannot be empty!";
}

EmptyStringArg::EmptyStringArg(
  const string& parameterName,
  const string& objectName
) : Exception(createWhat(parameterName, objectName)) {}

} // namespace onux
