#pragma once

namespace onux {

struct IInput {
  virtual ~IInput() {}

  virtual void mousePositionEvent(
    const double xPosition,
    const double yPosition
  ) = 0;
};

} // namespace onux
