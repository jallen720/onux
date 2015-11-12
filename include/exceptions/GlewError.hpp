#pragma once

#include "exceptions/Exception.hpp"

namespace onux {

class GlewError : public Exception {
public:
  GlewError(const std::string& what);
};

} // namespace onux
