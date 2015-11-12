#include "exceptions/GlewError.hpp"

using std::string;

namespace onux {

static const string createWhat(const string& what) {
  return "GLEW ERROR: " + what;
}

GlewError::GlewError(const string& what)
  : Exception(createWhat(what)) {}

} // namespace onux
