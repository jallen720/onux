#pragma once

#include <glm/glm.hpp>

namespace onux {

struct IMouseDeltaListener {
    virtual ~IMouseDeltaListener() {};
    virtual void onMouseDelta(const glm::dvec2& delta) = 0;
};

} // namespace onux
