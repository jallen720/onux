#pragma once

#include <string>

#include "exceptions/Error.hpp"

namespace onux {

class FileError : public Error {
public:
    FileError(
        const std::string& path,
        const std::string& function,
        const std::string& message
    );
};

} // namespace onux
