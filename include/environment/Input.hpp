#pragma once

#include "environment/events/MouseMoveEvent.hpp"

struct GLFWwindow;

namespace onux {

class Input {
public:
  Input(GLFWwindow* glfwWindow);
  MouseMoveEvent& getMouseMoveEvent();

private:
  MouseMoveEvent& m_mouseMoveEvent;
};

} // namespace onux
