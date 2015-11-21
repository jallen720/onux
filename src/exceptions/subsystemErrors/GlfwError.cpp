#include "exceptions/subsystemErrors/GlfwError.hpp"

#include "exceptions/messageBuilders/buildSystemMessage.hpp"

using std::string;
using std::to_string;

namespace onux {

static const string SYSTEM_NAME = "GLFW";

static const string buildGlfwMessage(const int code, const char* info) {
  return buildSystemMessage(
    SYSTEM_NAME,
    "\n"
    "  code: " + to_string(code) + "\n"
    "  info: " + info + "\n"
  );
}

GlfwError::GlfwError(const int code, const char* info)
  : Error(buildGlfwMessage(code, info)) {}

GlfwError::GlfwError(const string& message)
  : Error(buildSystemMessage(SYSTEM_NAME, message)) {}

} // namespace onux
