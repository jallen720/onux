#pragma once

#include <GL/glew.h>

#include "exceptions/Error.hpp"

namespace onux {

class GLError : public Error {
public:
  explicit GLError(const GLenum error);
};

} // namespace onux
