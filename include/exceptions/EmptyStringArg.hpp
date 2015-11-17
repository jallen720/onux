#pragma once

#include "exceptions/Exception.hpp"

namespace onux {

class EmptyStringArg : public Exception {
public:
  EmptyStringArg(
    const std::string& parameterName,
    const std::string& objectName
  );
};

} // namespace onux
