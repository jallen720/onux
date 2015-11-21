#pragma once

#include "exceptions/Error.hpp"

namespace onux {

class NullArg : public Error {
public:
  NullArg(
    const std::string& parameterName,
    const std::string& objectName
  );
};

} // namespace onux
