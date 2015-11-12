#pragma once

#include <GL/glew.h>

#include "exceptions/Exception.hpp"

namespace onux {

class OpenGlError : public Exception {
public:
  OpenGlError(const GLenum error);
};

} // namespace onux
