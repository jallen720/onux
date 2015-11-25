#pragma once

#include <string>

namespace onux {

const std::string buildArgMessage(
    const std::string& parameterName,
    const std::string& functionName,
    const std::string& argumentInfo,
    const std::string& argumentDescription = "argument"
);

} // namespace onux
