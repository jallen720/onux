#pragma once

#include <vector>

#include "exceptions/Exception.hpp"

namespace onux {

class InvalidMapKey : public Exception {
public:
  InvalidMapKey(
    const std::string&              parameterName,
    const std::string&              objectName,
    const std::string&              key,
    const std::vector<std::string>& validKeys
  );
};

} // namespace onux
