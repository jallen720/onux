#pragma once

#include <string>

namespace onux {

const std::string buildArgMessage(
    const std::string& parameter,
    const std::string& function,
    const std::string& argInfo,
    const std::string& argDescription = "argument"
);

} // namespace onux
