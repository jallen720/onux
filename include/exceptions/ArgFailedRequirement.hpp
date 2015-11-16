#pragma once

#include "exceptions/Exception.hpp"

namespace onux {

class ArgFailedRequirement : public Exception {
public:
  ArgFailedRequirement(
    const std::string& parameterName,
    const std::string& objectName,
    const std::string& requirement
  );
};

} // namespace onux
