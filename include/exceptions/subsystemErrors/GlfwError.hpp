#pragma once

#include "exceptions/Error.hpp"

namespace onux {

class GlfwError : public Error {
public:
  GlfwError(const int code, const char* description);
  GlfwError(const std::string& message);
};

} // namespace onux
