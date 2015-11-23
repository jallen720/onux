#include "environment/Environment.hpp"

#include <GLFW/glfw3.h>

#include "exceptions/subsystemErrors/GlfwError.hpp"

namespace onux {

static void setErrorCB() {
  glfwSetErrorCallback([](const int code, const char* description) {
    throw GlfwError(code, description);
  });
}

static void validateInit(const int initResult) {
  if (initResult == GL_FALSE) {
    throw GlfwError("failed to initialize");
  }
}

Environment::Environment() {
  setErrorCB();
  validateInit(glfwInit());
}

Environment::~Environment() {
  glfwTerminate();
}

} // namespace onux
