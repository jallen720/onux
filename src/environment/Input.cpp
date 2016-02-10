#include "environment/Input.hpp"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "environment/inputRegistry.hpp"
#include "environment/events/MouseMoveEvent.hpp"
#include "environment/events/MouseDeltaEvent.hpp"
#include "exceptions/validators/validateNotNull.hpp"

using glm::dvec2;

namespace onux {

struct Input::Impl {
    const Window    window;
    MouseMoveEvent  mouseMoveEvent;
    MouseDeltaEvent mouseDeltaEvent;

    Impl(const Window window);
};

static const Input::Window getValidWindow(const Input::Window window) {
    validateNotNull("window", "Input::Input", window);
    return window;
}

Input::Input(Window window)
    : impl(new Impl(getValidWindow(window))) {
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

Input::Impl::Impl(const Window window)
    : window(window) {}

} // namespace onux
