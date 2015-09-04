#pragma once

#include "ViewTransform.hpp"
#include <glm/glm.hpp>

using glm::mat4;

class Camera {
  ViewTransform viewTransform;
  mat4 projection;

public:
  Camera(const mat4& projection);
  ViewTransform& getViewTransform();
  const mat4& getProjection() const;
};
