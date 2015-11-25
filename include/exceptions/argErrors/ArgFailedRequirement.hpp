#pragma once

#include "exceptions/Error.hpp"

namespace onux {

class ArgFailedRequirement : public Error {
public:
    ArgFailedRequirement(
        const std::string& parameter,
        const std::string& function,
        const std::string& requirement
    );
};

} // namespace onux
