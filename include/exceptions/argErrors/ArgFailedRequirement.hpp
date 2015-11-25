#pragma once

#include "exceptions/Error.hpp"

namespace onux {

class ArgFailedRequirement : public Error {
public:
    ArgFailedRequirement(
        const std::string& parameterName,
        const std::string& functionName,
        const std::string& requirement
    );
};

} // namespace onux
