#pragma once

#include <string>

namespace onux {

void validateStringArg(
    const std::string& parameter,
    const std::string& function,
    const std::string& arg
);

void validateStringArg(
    const std::string& parameter,
    const std::string& function,
    const char*        arg
);

} // namespace onux
