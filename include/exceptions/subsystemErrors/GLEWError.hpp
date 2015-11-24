#pragma once

#include "exceptions/Error.hpp"

namespace onux {

class GLEWError : public Error {
public:
  GLEWError(const std::string& message);
};

} // namespace onux
