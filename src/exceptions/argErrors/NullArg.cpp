#include "exceptions/argErrors/NullArg.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"

using std::string;

namespace onux {

NullArg::NullArg(
  const string& parameterName,
  const string& objectName
) : Error(buildArgMessage(
      parameterName,
      objectName,
      " cannot be null"
    )) {}

} // namespace onux
