#include "sample/CameraControls.hpp"

#include <GLFW/glfw3.h>

using onux::Transform;
using onux::Input;
using glm::vec3;

CameraControls::CameraControls(Transform& cameraTransform, Input& input)
  : m_cameraTransform(cameraTransform)
  , m_input(input)
  , m_onMouseMove([&](const double x, const double y) {
      onMouseMove(x, y);
    })
  , m_previousX(-1.0)
  , m_previousY(-1.0) {
  m_input.getMouseMoveEvent().add(&m_onMouseMove);
}

CameraControls::~CameraControls() {
  m_input.getMouseMoveEvent().remove(&m_onMouseMove);
}

void CameraControls::onMouseMove(const double x, const double y) {
  static const auto DAMPING = 12.0f;

  if (m_previousX != -1.0) {
    m_cameraTransform.rotate(getRotation(x, y) / DAMPING);
  }

  m_previousX = x;
  m_previousY = y;
}

const vec3 CameraControls::getRotation(const double x, const double y) const {
  return vec3(m_previousY - y, m_previousX - x, 0.0f);
}
