#include "environment/inputRegistry.hpp"

#include <map>
#include <stdexcept>
#include <GLFW/glfw3.h>

#include "environment/interfaces/IInput.hpp"

using std::map;
using std::runtime_error;

namespace onux {

static map<const GLFWwindow*, IInput*> inputs;

static void validateInput(const IInput* input) {
  if (input == nullptr) {
    throw runtime_error("Cannot register null input!");
  }
}

static void validateWindow(const GLFWwindow* window) {
  if (window == nullptr) {
    throw runtime_error("Cannot register input for null window!");
  }
}

static const bool hasInput(const GLFWwindow* window) {
  return inputs.count(window) != 0;
}

static void cursorPosCallback(
  GLFWwindow*  window,
  const double x,
  const double y
) {
  if (hasInput(window)) {
    inputs[window]->cursorPosEvent(x, y);
  }
}

void registerInput(IInput* input, GLFWwindow* window) {
  validateInput(input);
  validateWindow(window);
  inputs[window] = input;
  glfwSetCursorPosCallback(window, cursorPosCallback);
}

void unregisterInput(const GLFWwindow* window) {
  inputs.erase(window);
}

} // namespace onux
