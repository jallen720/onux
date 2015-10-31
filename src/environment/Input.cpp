#include "environment/Input.hpp"

#include <stdexcept>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "environment/inputRegistry.hpp"

using std::runtime_error;
using glm::dvec2;

namespace onux {

static void validateWindow(const GLFWwindow* window) {
  if (window == nullptr) {
    throw runtime_error("Cannot create input for null window!");
  }
}

Input::Input(GLFWwindow* window)
  : m_window(window) {
  validateWindow(window);
  registerInput(this, window);
}

Input::~Input() {
  unregisterInput(m_window);
}

void Input::cursorPosEvent(const double x, const double y) {
  const dvec2 mousePosition(x, y);
  m_mouseMoveEvent.trigger(mousePosition);
  m_mouseDeltaEvent.trigger(mousePosition);
}

MouseMoveEvent& Input::getMouseMoveEvent() {
  return m_mouseMoveEvent;
}

MouseDeltaEvent& Input::getMouseDeltaEvent() {
  return m_mouseDeltaEvent;
}

} // namespace onux
