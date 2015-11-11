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

typedef const GLFWwindow* Window;

struct Input::Impl {
  Window          window;
  MouseMoveEvent  mouseMoveEvent;
  MouseDeltaEvent mouseDeltaEvent;

  Impl(Window window);
};

Input::Input(GLFWwindow* window)
  : impl(new Impl(window)) {
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

static void validateWindow(Window window) {
  if (window == nullptr) {
    throw runtime_error("Cannot create input for null window!");
  }
}

static Window loadWindow(Window window) {
  validateWindow(window);
  return window;
}

Input::Impl::Impl(Window window)
  : window(loadWindow(window)) {}

} // namespace onux
