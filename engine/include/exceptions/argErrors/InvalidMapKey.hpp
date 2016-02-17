#pragma once

#include <vector>

#include "exceptions/Error.hpp"

namespace onux {

class InvalidMapKey : public Error {
public:
    InvalidMapKey(
        const std::string&              parameter,
        const std::string&              function,
        const std::vector<std::string>& validKeys
    );
};

} // namespace onux
