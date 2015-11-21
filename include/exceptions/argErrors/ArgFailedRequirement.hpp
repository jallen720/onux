#pragma once

#include "exceptions/Error.hpp"

namespace onux {

class ArgFailedRequirement : public Error {
public:
  ArgFailedRequirement(
    const std::string& parameterName,
    const std::string& objectName,
    const std::string& requirement
  );
};

} // namespace onux
