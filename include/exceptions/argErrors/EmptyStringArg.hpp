#pragma once

#include "exceptions/Error.hpp"

namespace onux {

class EmptyStringArg : public Error {
public:
    EmptyStringArg(
        const std::string& parameterName,
        const std::string& functionName
    );
};

} // namespace onux
