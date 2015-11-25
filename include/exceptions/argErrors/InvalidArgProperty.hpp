#pragma once

#include <vector>

#include "exceptions/Error.hpp"

namespace onux {

class InvalidArgProperty : public Error {
public:
    InvalidArgProperty(
        const std::string& parameterName,
        const std::string& functionName,
        const std::string& propertyName,
        const std::string& validProperty
    );
    InvalidArgProperty(
        const std::string&              parameterName,
        const std::string&              functionName,
        const std::string&              propertyName,
        const std::vector<std::string>& validProperties
    );
};

} // namespace onux
