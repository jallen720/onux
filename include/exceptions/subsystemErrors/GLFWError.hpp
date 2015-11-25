#pragma once

#include "exceptions/Error.hpp"

namespace onux {

class GLFWError : public Error {
public:
    GLFWError(const int code, const char* description);
    explicit GLFWError(const std::string& message);
};

} // namespace onux
