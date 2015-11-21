#pragma once

#include "exceptions/Error.hpp"

namespace onux {

class GlewError : public Error {
public:
  GlewError(const std::string& message);
};

} // namespace onux
