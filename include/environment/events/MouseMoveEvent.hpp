#pragma once

#include "environment/events/Event.hpp"
#include "environment/listeners/IMouseMoveListener.hpp"

namespace onux {

class MouseMoveEvent
  : public Event<IMouseMoveListener, const double, const double> {

public:
  // Event
  void trigger(const double xPosition, const double yPosition) override;
};

} // namespace onux
