#include "exceptions/argErrors/InvalidArg.hpp"

#include "exceptions/messageBuilders/buildArgMessage.hpp"
#include "exceptions/messageBuilders/buildArgInfo.hpp"
#include "exceptions/messageBuilders/buildMustBe.hpp"

using std::string;
using std::vector;

namespace onux {

static const string buildInvalidArgMessage(
  const string& parameterName,
  const string& objectName,
  const string& mustBe
) {
  return buildArgMessage(
    parameterName,
    objectName,
    buildArgInfo(mustBe)
  );
}

InvalidArg::InvalidArg(
  const string& parameterName,
  const string& objectName,
  const string& validArgument
) : Error(buildInvalidArgMessage(
      parameterName,
      objectName,
      validArgument
    )) {}

InvalidArg::InvalidArg(
  const string&         parameterName,
  const string&         objectName,
  const vector<string>& validArguments
) : Error(buildInvalidArgMessage(
      parameterName,
      objectName,
      buildMustBe(validArguments)
    )) {}

} // namespace onux
