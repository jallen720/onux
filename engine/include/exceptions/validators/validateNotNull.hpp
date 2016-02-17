#pragma once

#include <string>

namespace onux {

void validateNotNull(
    const std::string& parameter,
    const std::string& function,
    const void*        arg
);

} // namespace onux
