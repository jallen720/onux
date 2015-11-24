#pragma once

#include <memory>

#include "environment/interfaces/IInput.hpp"

struct GLFWwindow;

namespace onux {

struct MouseMoveEvent;
struct MouseDeltaEvent;

class Input : public IInput {
public:
  explicit Input(GLFWwindow* window);
  ~Input();
  MouseMoveEvent& getMouseMoveEvent();
  MouseDeltaEvent& getMouseDeltaEvent();

  // IInput
  virtual void cursorPosEvent(const double x, const double y) override;

private:
  struct Impl;
  std::unique_ptr<Impl> impl;
};

} // namespace onux
