#pragma once

#include "environment/InputEvents.hpp"

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
