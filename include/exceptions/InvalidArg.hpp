#pragma once

#include <vector>

#include "exceptions/Exception.hpp"

namespace onux {

class InvalidArg : public Exception {
public:
  InvalidArg(
    const std::string& parameterName,
    const std::string& objectName,
    const std::string& argument,
    const std::string& validArgument
  );
  InvalidArg(
    const std::string&              parameterName,
    const std::string&              objectName,
    const std::string&              argument,
    const std::vector<std::string>& validArguments
  );
};

} // namespace onux
