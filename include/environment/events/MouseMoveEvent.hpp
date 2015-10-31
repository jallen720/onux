#pragma once

#include <glm/glm.hpp>

#include "environment/events/Event.hpp"
#include "environment/listeners/IMouseMoveListener.hpp"

namespace onux {

class MouseMoveEvent : public Event<IMouseMoveListener, const glm::dvec2&> {
public:
  // Event
  void trigger(const glm::dvec2& position) override;
};

} // namespace onux
