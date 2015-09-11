#pragma once

#include "Transform.hpp"

class ViewTransform : public Transform {
protected:
  const glm::mat4 calculateMatrix(
    const glm::vec3& position,
    const glm::vec3& rotation,
    const glm::vec3& scale
  ) const override;
};
