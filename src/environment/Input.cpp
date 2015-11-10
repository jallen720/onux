#include "environment/Input.hpp"

#include <stdexcept>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "environment/inputRegistry.hpp"
#include "environment/events/MouseMoveEvent.hpp"
#include "environment/events/MouseDeltaEvent.hpp"

using std::runtime_error;
using glm::dvec2;

namespace onux {

struct Input::Impl {
  const GLFWwindow* window;
  MouseMoveEvent    mouseMoveEvent;
  MouseDeltaEvent   mouseDeltaEvent;

  Impl(const GLFWwindow* window);
};

static void validateWindow(const GLFWwindow* window) {
  if (window == nullptr) {
    throw runtime_error("Cannot create input for null window!");
  }
}

Input::Input(GLFWwindow* window)
  : impl(new Impl(window)) {
  validateWindow(window);
  registerInput(this, window);
}

Input::~Input() {
  unregisterInput(impl->window);
}

void Input::cursorPosEvent(const double x, const double y) {
  const dvec2 mousePosition(x, y);
  impl->mouseMoveEvent.trigger(mousePosition);
  impl->mouseDeltaEvent.trigger(mousePosition);
}

MouseMoveEvent& Input::getMouseMoveEvent() {
  return impl->mouseMoveEvent;
}

MouseDeltaEvent& Input::getMouseDeltaEvent() {
  return impl->mouseDeltaEvent;
}

// Implementation

Input::Impl::Impl(const GLFWwindow* window)
  : window(window) {}

} // namespace onux
