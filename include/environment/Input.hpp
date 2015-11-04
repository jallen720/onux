#pragma once

#include "environment/interfaces/IInput.hpp"
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
  void cursorPosEvent(const double x, const double y) override;

private:
  const GLFWwindow* m_window;
  MouseMoveEvent    m_mouseMoveEvent;
  MouseDeltaEvent   m_mouseDeltaEvent;
};

} // namespace onux
