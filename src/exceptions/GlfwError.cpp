#include "exceptions/GlfwError.hpp"

using std::string;
using std::to_string;

namespace onux {

static const string GLFW_ERROR_PREFIX = "GLFW ERROR";

static const string createWhat(const int code, const char* description) {
  return GLFW_ERROR_PREFIX + " [ " +
         to_string(code) + " ]: " +
         description;
}

static const string createWhat(const string& what) {
  return GLFW_ERROR_PREFIX + ": " + what;
}

GlfwError::GlfwError(const int code, const char* description)
  : Error(createWhat(code, description)) {}

GlfwError::GlfwError(const string& what)
  : Error(createWhat(what)) {}

} // namespace onux
