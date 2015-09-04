#pragma once

#include "Transform.hpp"

struct ViewTransform : Transform {
protected:
  const mat4 calculateMatrix(
    const vec3& scale,
    const vec3& rotation,
    const vec3& position
  ) const override;
};
