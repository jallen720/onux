#pragma once

#include <string>
#include <GL/glew.h>

using std::string;

const string readFile(const string& path);
const string fileExtension(const string& path);
const string getErrorMsg(const GLenum errorCode);
