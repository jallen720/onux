#pragma once

struct GLFWwindow;

namespace onux {

class MouseMoveEvent;

class Input {
public:
  Input(GLFWwindow* glfwWindow);
  MouseMoveEvent& getMouseMoveEvent();

private:
  MouseMoveEvent& m_mouseMoveEvent;
};

} // namespace onux
