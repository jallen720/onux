#include "sample/CameraControls.hpp"

using onux::Transform;
using onux::MouseMoveEvent;
using glm::vec3;

CameraControls::CameraControls(
  Transform& cameraTransform,
  MouseMoveEvent& mouseMoveEvent
) : m_cameraTransform(cameraTransform)
  , m_mouseMoveEvent(mouseMoveEvent)
  , m_onMouseMove([&](const double x, const double y) {
      static const float DAMPING = 12.0f;

      if (m_previousX != -1.0) {
        m_cameraTransform.rotate(getRotation(x, y) / DAMPING);
      }

      m_previousX = x;
      m_previousY = y;
    })
  , m_previousX(-1.0)
  , m_previousY(-1.0) {
  m_mouseMoveEvent.add(&m_onMouseMove);
}

CameraControls::~CameraControls() {
  m_mouseMoveEvent.remove(&m_onMouseMove);
}

const vec3 CameraControls::getRotation(const double x, const double y) const {
  return vec3(m_previousY - y, m_previousX - x, 0.0f);
}
