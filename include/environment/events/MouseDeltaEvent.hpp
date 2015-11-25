#pragma once

#include <memory>
#include <glm/glm.hpp>

#include "environment/events/Event.hpp"

namespace onux {

struct IMouseDeltaListener;

class MouseDeltaEvent : public Event<IMouseDeltaListener, const glm::dvec2&> {
public:
    MouseDeltaEvent();
    ~MouseDeltaEvent();

    // Event
    virtual void trigger(const glm::dvec2& position) override;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace onux
