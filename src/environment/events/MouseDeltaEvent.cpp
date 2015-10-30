#include "environment/events/MouseDeltaEvent.hpp"

using glm::dvec2;

#define PREV_MOUSE_POS_UNSET -10000.0

namespace onux {

MouseDeltaEvent::MouseDeltaEvent()
  : m_prevMousePos(PREV_MOUSE_POS_UNSET) {}

void MouseDeltaEvent::trigger(const double xPosition, const double yPosition) {
  const dvec2 currMousePos(xPosition, yPosition);
  callListeners(getDelta(currMousePos));
  m_prevMousePos = currMousePos;
}

const dvec2 MouseDeltaEvent::getDelta(const dvec2& currMousePos) {
  return prevMousePosIsSet()
         ? m_prevMousePos - currMousePos
         : dvec2();
}

const bool MouseDeltaEvent::prevMousePosIsSet() const {
  return m_prevMousePos.x != PREV_MOUSE_POS_UNSET;
}

void MouseDeltaEvent::callListeners(const dvec2& delta) {
  for (Listener listener : getListeners()) {
    listener->onMouseDelta(delta);
  }
}

} // namespace onux
