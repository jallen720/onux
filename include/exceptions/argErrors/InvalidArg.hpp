#pragma once

#include <vector>

#include "exceptions/Error.hpp"

namespace onux {

class InvalidArg : public Error {
public:
    InvalidArg(
        const std::string& parameterName,
        const std::string& functionName,
        const std::string& validArgument
    );
    InvalidArg(
        const std::string&              parameterName,
        const std::string&              functionName,
        const std::vector<std::string>& validArguments
    );
};

} // namespace onux
