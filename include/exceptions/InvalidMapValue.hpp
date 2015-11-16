#pragma once

#include <vector>

#include "exceptions/Exception.hpp"

namespace onux {

class InvalidMapValue : public Exception {
public:
  InvalidMapValue(
    const std::string&              parameterName,
    const std::string&              objectName,
    const std::string&              key,
    const std::string&              value,
    const std::vector<std::string>& validValues
  );
};

} // namespace onux
