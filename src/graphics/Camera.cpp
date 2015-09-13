#include "graphics/Camera.hpp"

using glm::mat4;

namespace onux {

Camera::Camera(const mat4& projection)
  : m_projection(projection) {}

Transform& Camera::getTransform() {
  return m_transform;
}

const mat4& Camera::getProjection() const {
  return m_projection;
}

} // namespace onux
