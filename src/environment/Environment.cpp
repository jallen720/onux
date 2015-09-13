#include "environment/Environment.hpp"

#include <sstream>
#include <stdexcept>
#include <GLFW/glfw3.h>

using std::stringstream;
using std::runtime_error;

namespace onux {

static void setErrorCB() {
  glfwSetErrorCallback([](const int code, const char* description) {
    stringstream errorMsg;
    errorMsg << "GLFW ERROR [" << code << "]: " << description;
    throw runtime_error(errorMsg.str());
  });
}

static void validateInit(const int initResult) {
  if (initResult == GL_FALSE) {
    throw runtime_error("GLFW failed to initialize!");
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
