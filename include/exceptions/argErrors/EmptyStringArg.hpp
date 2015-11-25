#pragma once

#include "exceptions/Error.hpp"

namespace onux {

class EmptyStringArg : public Error {
public:
    EmptyStringArg(
        const std::string& parameter,
        const std::string& function
    );
};

} // namespace onux
