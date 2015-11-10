#include "environment/events/MouseMoveEvent.hpp"

#include "environment/interfaces/IMouseMoveListener.hpp"

using glm::dvec2;

namespace onux {

void MouseMoveEvent::trigger(const dvec2& position) {
  for (Listener listener : getListeners()) {
    listener->onMouseMove(position);
  }
}

} // namespace onux
