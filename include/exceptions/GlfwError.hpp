#pragma once

#include "exceptions/Exception.hpp"

namespace onux {

class GlfwError : public Exception {
public:
  GlfwError(const int code, const char* description);
  GlfwError(const std::string& what);
};

} // namespace onux
