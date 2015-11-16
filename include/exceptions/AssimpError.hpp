#pragma once

#include "exceptions/Exception.hpp"

namespace onux {

class AssimpError : public Exception {
public:
  AssimpError(const std::string& what);
};

} // namespace onux
