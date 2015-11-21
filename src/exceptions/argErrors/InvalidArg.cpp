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
  const string& argument,
  const string& mustBe
) {
  return buildArgMessage(
    parameterName,
    objectName,
    buildArgInfo(
      argument,
      mustBe
    )
  );
}

InvalidArg::InvalidArg(
  const string& parameterName,
  const string& objectName,
  const string& argument,
  const string& validArgument
) : Error(buildInvalidArgMessage(
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
) : Error(buildInvalidArgMessage(
      parameterName,
      objectName,
      argument,
      buildMustBe(validArguments)
    )) {}

} // namespace onux
