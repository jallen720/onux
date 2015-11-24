#include "environment/events/MouseDeltaEvent.hpp"

#include "environment/interfaces/IMouseDeltaListener.hpp"

using glm::dvec2;

namespace onux {

struct MouseDeltaEvent::Impl {
  typedef MouseDeltaEvent* Self;

  Self self;
  dvec2 previousPosition;

  Impl(Self self);
  const dvec2 getDelta(const dvec2& position);
  const bool previousPositionIsSet() const;
  void callListeners(const dvec2& delta);
};

MouseDeltaEvent::MouseDeltaEvent()
  : impl(new Impl(this)) {}

MouseDeltaEvent::~MouseDeltaEvent() {}

void MouseDeltaEvent::trigger(const dvec2& position) {
  impl->callListeners(impl->getDelta(position));
  impl->previousPosition = position;
}

// Implementation

static const double PREVIOUS_POSITION_UNSET = -10000.0;

MouseDeltaEvent::Impl::Impl(Self self)
  : self(self)
  , previousPosition(PREVIOUS_POSITION_UNSET) {}

const dvec2 MouseDeltaEvent::Impl::getDelta(const dvec2& position) {
  return previousPositionIsSet()
         ? previousPosition - position
         : dvec2();
}

const bool MouseDeltaEvent::Impl::previousPositionIsSet() const {
  return previousPosition.x != PREVIOUS_POSITION_UNSET;
}

void MouseDeltaEvent::Impl::callListeners(const dvec2& delta) {
  for (Listener listener : self->getListeners()) {
    listener->onMouseDelta(delta);
  }
}

} // namespace onux
