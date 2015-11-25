#pragma once

#include <vector>

#include "exceptions/Error.hpp"

namespace onux {

class InvalidMapKey : public Error {
public:
    InvalidMapKey(
        const std::string&              parameterName,
        const std::string&              objectName,
        const std::vector<std::string>& validKeys
    );
};

} // namespace onux
