#include "environment/Input.hpp"

#include <GLFW/glfw3.h>

#include "environment/inputRegistry.hpp"

namespace onux {

Input::Input(GLFWwindow* window)
  : m_window(window) {
  registerInput(this, window);
}

Input::~Input() {
  unregisterInput(m_window);
}

void Input::cursorPosEvent(const double x, const double y) {
  m_mouseMoveEvent.trigger(x, y);
  m_mouseDeltaEvent.trigger(x, y);
}

MouseMoveEvent& Input::getMouseMoveEvent() {
  return m_mouseMoveEvent;
}

MouseDeltaEvent& Input::getMouseDeltaEvent() {
  return m_mouseDeltaEvent;
}

} // namespace onux
