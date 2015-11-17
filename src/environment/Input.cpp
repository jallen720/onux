#include "environment/Input.hpp"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "environment/inputRegistry.hpp"
#include "environment/events/MouseMoveEvent.hpp"
#include "environment/events/MouseDeltaEvent.hpp"
#include "exceptions/NullArg.hpp"

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
    throw NullArg("window", "Input");
  }
}

static Window getValidWindow(Window window) {
  validateWindow(window);
  return window;
}

Input::Impl::Impl(Window window)
  : window(getValidWindow(window)) {}

} // namespace onux
