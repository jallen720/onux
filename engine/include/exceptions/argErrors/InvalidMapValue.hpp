#pragma once

#include <vector>

#include "exceptions/Error.hpp"

namespace onux {

class InvalidMapValue : public Error {
public:
    InvalidMapValue(
        const std::string&              parameter,
        const std::string&              function,
        const std::string&              key,
        const std::vector<std::string>& validValues
    );
};

} // namespace onux
