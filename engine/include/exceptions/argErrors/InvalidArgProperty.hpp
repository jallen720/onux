#pragma once

#include <vector>

#include "exceptions/Error.hpp"

namespace onux {

class InvalidArgProperty : public Error {
public:
    InvalidArgProperty(
        const std::string& parameter,
        const std::string& function,
        const std::string& property,
        const std::string& validProperty
    );
    InvalidArgProperty(
        const std::string&              parameter,
        const std::string&              function,
        const std::string&              property,
        const std::vector<std::string>& validProperties
    );
};

} // namespace onux
