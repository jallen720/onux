#include "exceptions/ArgFailedRequirement.hpp"

using std::string;

namespace onux {

static const string createWhat(
  const string& parameterName,
  const string& objectName,
  const string& requirement
) {
  return "\n  Argument passed to \"" +
         parameterName + "\" parameter for " +
         objectName + " failed requirement:\n    " +
         requirement;
}

ArgFailedRequirement::ArgFailedRequirement(
  const string& parameterName,
  const string& objectName,
  const string& requirement
) : Error(createWhat(
      parameterName,
      objectName,
      requirement
    )) {}

} // namespace onux
