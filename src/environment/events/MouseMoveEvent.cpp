#include "environment/events/MouseMoveEvent.hpp"

using glm::dvec2;

namespace onux {

void MouseMoveEvent::trigger(const double xPosition, const double yPosition) {
  callListeners(dvec2(xPosition, yPosition));
}

void MouseMoveEvent::callListeners(const dvec2& position) {
  for (Listener listener : getListeners()) {
    listener->onMouseMove(position);
  }
}

} // namespace onux
