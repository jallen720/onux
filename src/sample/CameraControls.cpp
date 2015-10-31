#include "sample/CameraControls.hpp"

using glm::vec3;
using glm::dvec2;
using onux::Transform;
using onux::Input;

CameraControls::CameraControls(Transform& cameraTransform, Input& input)
  : m_cameraTransform(cameraTransform)
  , m_input(input) {
  m_input.getMouseDeltaEvent()
         .add(this);
}

CameraControls::~CameraControls() {
  m_input.getMouseDeltaEvent()
         .remove(this);
}

static const vec3 getRotation(const dvec2& delta) {
  return vec3(delta.y, delta.x, 0.0f);
}

void CameraControls::onMouseDelta(const dvec2& delta) {
  static const auto DAMPING = 12.0f;
  m_cameraTransform.rotate(getRotation(delta) / DAMPING);
}
