#include "Environment.hpp"

#include <sstream>
#include <stdexcept>
#include <GLFW/glfw3.h>

using std::stringstream;
using std::runtime_error;

static void setErrorCB() {
  glfwSetErrorCallback([](const int code, const char* description) {
    stringstream errorMsg;
    errorMsg << "GLFW ERROR [" << code << "]: " << description;
    throw runtime_error(errorMsg.str());
  });
}

Environment::Environment() {
  setErrorCB();
  glfwInit();
}

Environment::~Environment() {
  glfwTerminate();
}
