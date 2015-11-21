#pragma once

#include "exceptions/Error.hpp"

namespace onux {

class AssimpError : public Error {
public:
  AssimpError(const std::string& message);
};

} // namespace onux