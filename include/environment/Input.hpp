#pragma once

#include "environment/events/MouseMoveEvent.hpp"
#include "environment/events/MouseDeltaEvent.hpp"

struct GLFWwindow;

namespace onux {

class Input {
public:
  Input(GLFWwindow* glfwWindow);
  MouseMoveEvent& getMouseMoveEvent();
  MouseDeltaEvent& getMouseDeltaEvent();

private:
  MouseMoveEvent&  m_mouseMoveEvent;
  MouseDeltaEvent& m_mouseDeltaEvent;
};

} // namespace onux
