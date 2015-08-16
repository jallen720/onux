#pragma once

#include <string>
#include <GL/glew.h>

using std::string;

const GLint getInt(const GLenum parameter);
const string getErrorMsg(const GLenum errorCode);
