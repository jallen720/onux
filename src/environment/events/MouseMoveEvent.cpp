#include "environment/events/MouseMoveEvent.hpp"

#include <glm/glm.hpp>

using glm::dvec2;

namespace onux {

void MouseMoveEvent::trigger(const double xPosition, const double yPosition) {
  const dvec2 position(xPosition, yPosition);

  for (Listener listener : getListeners()) {
    listener->onMouseMove(position);
  }
}

} // namespace onux
