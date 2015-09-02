#pragma once

#include <string>
#include <functional>

using std::string;
using std::function;

const string readFile(const string& path);
const string fileExtension(const string& path);
void magickErrorFinder(const function<void()>&);
