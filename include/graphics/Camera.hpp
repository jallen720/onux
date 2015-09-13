#pragma once

#include "graphics/Transform.hpp"
#include <glm/glm.hpp>

namespace onux {

class Camera {
public:
  Camera(const glm::mat4& projection);
  Transform& getTransform();
  const glm::mat4& getProjection() const;

private:
  Transform m_transform;
  glm::mat4 m_projection;
};

} // namespace onux
