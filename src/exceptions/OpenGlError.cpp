#include "exceptions/OpenGlError.hpp"

#include "gl/helpers.hpp"

using std::string;

namespace onux {

static const string createWhat(const GLenum error) {
  return "OPENGL ERROR: " + getErrorMsg(error);
}

OpenGlError::OpenGlError(const GLenum error)
  : Exception(createWhat(error)) {}

} // namespace onux
