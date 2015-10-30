#pragma once

#include "environment/IInput.hpp"
#include "environment/events/MouseMoveEvent.hpp"
#include "environment/events/MouseDeltaEvent.hpp"

struct GLFWwindow;

namespace onux {

class Input : public IInput {
public:
  Input(GLFWwindow* window);
  ~Input();
  MouseMoveEvent& getMouseMoveEvent();
  MouseDeltaEvent& getMouseDeltaEvent();

  // IInput
  void mousePositionEvent(
    const double xPosition,
    const double yPosition
  ) override;

private:
  const GLFWwindow* m_window;
  MouseMoveEvent    m_mouseMoveEvent;
  MouseDeltaEvent   m_mouseDeltaEvent;
};

} // namespace onux
