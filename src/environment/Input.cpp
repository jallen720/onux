#include "environment/Input.hpp"

#include <GLFW/glfw3.h>

#include "environment/inputRegistry.hpp"

namespace onux {

Input::Input(GLFWwindow* window)
  : m_window(window) {
  registerInput(window, this);
}

Input::~Input() {
  unregisterInput(m_window);
}

void Input::mousePositionEvent(const double xPosition, const double yPosition) {
  m_mouseMoveEvent.trigger(xPosition, yPosition);
  m_mouseDeltaEvent.trigger(xPosition, yPosition);
}

MouseMoveEvent& Input::getMouseMoveEvent() {
  return m_mouseMoveEvent;
}

MouseDeltaEvent& Input::getMouseDeltaEvent() {
  return m_mouseDeltaEvent;
}

} // namespace onux
