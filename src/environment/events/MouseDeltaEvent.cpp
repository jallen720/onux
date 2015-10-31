#include "environment/events/MouseDeltaEvent.hpp"

using glm::dvec2;

namespace onux {

static const double PREVIOUS_POSITION_UNSET = -10000.0;

MouseDeltaEvent::MouseDeltaEvent()
  : m_previousPosition(PREVIOUS_POSITION_UNSET) {}

void MouseDeltaEvent::trigger(const dvec2& position) {
  callListeners(getDelta(position));
  m_previousPosition = position;
}

const dvec2 MouseDeltaEvent::getDelta(const dvec2& position) {
  return previousPositionIsSet()
         ? m_previousPosition - position
         : dvec2();
}

const bool MouseDeltaEvent::previousPositionIsSet() const {
  return m_previousPosition.x != PREVIOUS_POSITION_UNSET;
}

void MouseDeltaEvent::callListeners(const dvec2& delta) {
  for (Listener listener : getListeners()) {
    listener->onMouseDelta(delta);
  }
}

} // namespace onux
