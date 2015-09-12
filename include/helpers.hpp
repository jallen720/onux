#pragma once

#include <string>
#include <functional>

namespace onux {

const std::string readFile(const std::string& path);
const std::string fileExtension(const std::string& path);
void magickErrorFinder(const std::function<void()>&);

} // namespace onux
