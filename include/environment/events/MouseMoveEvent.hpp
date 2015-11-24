#pragma once

#include <glm/glm.hpp>

#include "environment/events/Event.hpp"

namespace onux {

struct IMouseMoveListener;

class MouseMoveEvent : public Event<IMouseMoveListener, const glm::dvec2&> {
public:
  // Event
  virtual void trigger(const glm::dvec2& position) override;
};

} // namespace onux
