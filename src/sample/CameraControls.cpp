#include "sample/CameraControls.hpp"

using glm::vec3;
using glm::dvec2;
using onux::Transform;

CameraControls::CameraControls(Transform& cameraTransform)
  : m_cameraTransform(cameraTransform)
  , m_prevMousePos(-1.0, -1.0) {}

void CameraControls::onMouseMove(const dvec2& position) {
  static const auto DAMPING = 12.0f;

  if (m_prevMousePos.x != -1.0) {
    m_cameraTransform.rotate(getRotation(position) / DAMPING);
  }

  m_prevMousePos = position;
}

const vec3 CameraControls::getRotation(const dvec2& currMousePos) const {
  const dvec2 delta(m_prevMousePos - currMousePos);
  return vec3(delta.y, delta.x, 0.0f);
}
