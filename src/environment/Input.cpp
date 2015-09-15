#include "environment/Input.hpp"

#include <map>
#include <GLFW/glfw3.h>

#include "environment/MouseMoveEvent.hpp"

using std::map;

namespace onux {

static map<const GLFWwindow*, MouseMoveEvent> mouseMoveEvents;

static const bool hasMouseMoveEvent(const GLFWwindow* window) {
  return mouseMoveEvents.count(window) != 0;
}

static void cursorPosCallback(
  GLFWwindow* window,
  const double x,
  const double y
) {
  if (hasMouseMoveEvent(window)) {
    mouseMoveEvents[window].trigger(x, y);
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
