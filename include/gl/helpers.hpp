#pragma once

#include <string>
#include <GL/glew.h>

namespace onux {

const GLint getInt(const GLenum parameter);
const std::string getErrorMsg(const GLenum error);

} // namespace onux
