#pragma once

#include "ViewTransform.hpp"
#include <glm/glm.hpp>

class Camera {
public:
  Camera(const glm::mat4& projection);
  ViewTransform& getViewTransform();
  const glm::mat4& getProjection() const;

private:
  ViewTransform viewTransform;
  glm::mat4 projection;
};
