#pragma once

#include <vector>

#include "exceptions/Exception.hpp"

namespace onux {

class InvalidArgProperty : public Exception {
public:
  InvalidArgProperty(
    const std::string&              parameterName,
    const std::string&              objectName,
    const std::string&              propertyName,
    const std::string&              property,
    const std::vector<std::string>& validProperties
  );
};

} // namespace onux
