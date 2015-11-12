#pragma once

#include <stdexcept>
#include <string>

namespace onux {

class Exception : public std::runtime_error {
public:
  Exception(const std::string& what);
};

} // namespace onux
