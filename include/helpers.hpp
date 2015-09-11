#pragma once

#include <string>
#include <functional>

const std::string readFile(const std::string& path);
const std::string fileExtension(const std::string& path);
void magickErrorFinder(const std::function<void()>&);
