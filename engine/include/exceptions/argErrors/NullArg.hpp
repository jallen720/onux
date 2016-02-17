#pragma once

#include "exceptions/Error.hpp"

namespace onux {

class NullArg : public Error {
public:
    NullArg(
        const std::string& parameter,
        const std::string& function
    );
};

} // namespace onux
