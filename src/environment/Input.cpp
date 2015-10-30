#include "environment/Input.hpp"

#include <map>
#include <GLFW/glfw3.h>

using std::map;

namespace onux {

static map<const GLFWwindow*, MouseMoveEvent> mouseMoveEvents;

static const bool hasMouseMoveEvent(const GLFWwindow* window) {
  return mouseMoveEvents.count(window) != 0;
}

static void cursorPosCallback(
  GLFWwindow*  window,
  const double xPosition,
  const double yPosition
) {
  if (hasMouseMoveEvent(window)) {
    mouseMoveEvents[window].trigger(xPosition, yPosition);
  }
}

Input::Input(GLFWwindow* glfwWindow)
  : m_mouseMoveEvent(mouseMoveEvents[glfwWindow]) {
  glfwSetCursorPosCallback(glfwWindow, cursorPosCallback);
}

MouseMoveEvent& Input::getMouseMoveEvent() {
  return m_mouseMoveEvent;
}

} // namespace onux
