#pragma once

#include <glm/glm.hpp>

namespace onux {

struct IMouseMoveListener {
  virtual ~IMouseMoveListener() {};
  virtual void onMouseMove(const glm::dvec2& position) = 0;
};

} // namespace onux
