#include "environment/events/MouseDeltaEvent.hpp"

#include "environment/interfaces/IMouseDeltaListener.hpp"

using glm::dvec2;

namespace onux {

struct MouseDeltaEvent::Impl {
    using Self = MouseDeltaEvent*;

    Self  self;
    dvec2 previousPosition;

    const dvec2 getDelta(const dvec2& position);
    const bool previousPositionIsSet() const;
    void callListeners(const dvec2& delta);
};

static const auto PREVIOUS_POSITION_UNSET = dvec2(10000.0);

MouseDeltaEvent::MouseDeltaEvent()
    : impl(new Impl { this, PREVIOUS_POSITION_UNSET }) {}

MouseDeltaEvent::~MouseDeltaEvent() {}

void MouseDeltaEvent::trigger(const dvec2& position) {
    impl->callListeners(impl->getDelta(position));
    impl->previousPosition = position;
}

// Implementation

const dvec2 MouseDeltaEvent::Impl::getDelta(const dvec2& position) {
    return previousPositionIsSet()
           ? position - previousPosition
           : dvec2();
}

const bool MouseDeltaEvent::Impl::previousPositionIsSet() const {
    return previousPosition != PREVIOUS_POSITION_UNSET;
}

void MouseDeltaEvent::Impl::callListeners(const dvec2& delta) {
    for (Listener listener : self->getListeners()) {
        listener->onMouseDelta(delta);
    }
}

} // namespace onux
