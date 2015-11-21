#include "exceptions/argErrors/ArgFailedRequirement.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"

using std::string;

namespace onux {

ArgFailedRequirement::ArgFailedRequirement(
  const string& parameterName,
  const string& objectName,
  const string& requirement
) : Error(buildArgMessage(
      parameterName,
      objectName,
      " failed requirement:\n    " + requirement
    )) {}

} // namespace onux
