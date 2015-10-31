#pragma once

#include <glm/glm.hpp>

#include "environment/events/Event.hpp"
#include "environment/listeners/IMouseDeltaListener.hpp"

namespace onux {

class MouseDeltaEvent : public Event<IMouseDeltaListener, const glm::dvec2&> {
public:
  MouseDeltaEvent();

  // Event
  void trigger(const glm::dvec2& position) override;

private:
  glm::dvec2 m_prevMousePos;

  const glm::dvec2 getDelta(const glm::dvec2& currMousePos);
  const bool prevMousePosIsSet() const;
  void callListeners(const glm::dvec2& delta);
};

} // namespace onux
