#pragma once

#include <string>
#include <GL/glew.h>

namespace onux_gl {

const GLint getInt(const GLenum parameter);
const std::string getErrorMsg(const GLenum error);

} // namespace onux_gl
