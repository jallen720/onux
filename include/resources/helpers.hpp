#pragma once

#include <string>
#include <functional>

namespace onux {

void recursiveFileList(
  const std::string& baseDir,
  const std::function<void(const std::string&)> callback
);

} // namespace onux
