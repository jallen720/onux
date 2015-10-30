#include "environment/inputRegistry.hpp"

#include <map>
#include <GLFW/glfw3.h>

#include "environment/IInput.hpp"

using std::map;

namespace onux {

static map<const GLFWwindow*, IInput*> inputs;

static const bool hasInput(const GLFWwindow* window) {
  return inputs.count(window) != 0;
}

static void cursorPosCallback(
  GLFWwindow*  window,
  const double xPosition,
  const double yPosition
) {
  if (hasInput(window)) {
    inputs[window]->mousePositionEvent(xPosition, yPosition);
  }
}

void registerInput(GLFWwindow* window, IInput* input) {
  inputs[window] = input;
  glfwSetCursorPosCallback(window, cursorPosCallback);
}

void unregisterInput(const GLFWwindow* window) {
  inputs.erase(window);
}

} // namespace onux
