#include "exceptions/argErrors/EmptyStringArg.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"

using std::string;

namespace onux {

EmptyStringArg::EmptyStringArg(
  const string& parameterName,
  const string& objectName
) : Error(buildArgMessage(
      parameterName,
      objectName,
      " cannot be empty",
      "string argument"
    )) {}

} // namespace onux
