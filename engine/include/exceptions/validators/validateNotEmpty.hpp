#pragma once

#include <string>

namespace onux {

void validateNotEmpty(
    const std::string& parameter,
    const std::string& function,
    const std::string& arg
);

void validateNotEmpty(
    const std::string& parameter,
    const std::string& function,
    const char*        arg
);

} // namespace onux
