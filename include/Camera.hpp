#pragma once

#include "ViewTransform.hpp"
#include <glm/glm.hpp>

namespace onux {

class Camera {
public:
  Camera(const glm::mat4& projection);
  ViewTransform& getViewTransform();
  const glm::mat4& getProjection() const;

private:
  ViewTransform m_viewTransform;
  glm::mat4     m_projection;
};

} // namespace onux
