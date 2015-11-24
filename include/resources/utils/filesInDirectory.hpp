#pragma once

#include <string>
#include <functional>

namespace onux {

void filesInDirectory(
  const std::string& directory,
  const std::function<void(const std::string&)> callback
);

} // namespace onux
