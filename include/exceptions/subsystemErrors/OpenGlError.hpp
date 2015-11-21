#pragma once

#include <GL/glew.h>

#include "exceptions/Error.hpp"

namespace onux {

class OpenGlError : public Error {
public:
  OpenGlError(const GLenum error);
};

} // namespace onux
