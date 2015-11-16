#pragma once

#include "exceptions/Exception.hpp"

namespace onux {

class NullArg : public Exception {
public:
  NullArg(
    const std::string& parameterName,
    const std::string& objectName
  );
};

} // namespace onux
