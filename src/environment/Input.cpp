#include "environment/Input.hpp"

#include <map>
#include <GLFW/glfw3.h>

using std::map;

namespace onux {

static map<const GLFWwindow*, MouseMoveEvent> mouseMoveEvents;
static map<const GLFWwindow*, MouseDeltaEvent> mouseDeltaEvents;

static const bool hasMouseMoveEvent(const GLFWwindow* window) {
  return mouseMoveEvents.count(window) != 0;
}

static const bool hasMouseDeltaEvent(const GLFWwindow* window) {
  return mouseDeltaEvents.count(window) != 0;
}

static void cursorPosCallback(
  GLFWwindow*  window,
  const double xPosition,
  const double yPosition
) {
  if (hasMouseMoveEvent(window)) {
    mouseMoveEvents[window].trigger(xPosition, yPosition);
  }

  if (hasMouseDeltaEvent(window)) {
    mouseDeltaEvents[window].trigger(xPosition, yPosition);
  }
}

Input::Input(GLFWwindow* glfwWindow)
  : m_mouseMoveEvent(mouseMoveEvents[glfwWindow])
  , m_mouseDeltaEvent(mouseDeltaEvents[glfwWindow]) {
  glfwSetCursorPosCallback(glfwWindow, cursorPosCallback);
}

MouseMoveEvent& Input::getMouseMoveEvent() {
  return m_mouseMoveEvent;
}

MouseDeltaEvent& Input::getMouseDeltaEvent() {
  return m_mouseDeltaEvent;
}

} // namespace onux
