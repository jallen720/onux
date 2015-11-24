#pragma once

#include "exceptions/Error.hpp"

namespace onux {

class GLEWError : public Error {
public:
  explicit GLEWError(const std::string& message);
};

} // namespace onux
