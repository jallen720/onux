#pragma once

#include <string>
#include <GL/glew.h>

namespace onux_gl {
  using std::string;

  const GLint getInt(const GLenum parameter);
  const string getErrorMsg(const GLenum error);
}
