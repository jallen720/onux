#pragma once

#include <glm/glm.hpp>

#include "graphics/Transform.hpp"
#include "environment/MouseMoveEvent.hpp"

class CameraControls {
public:
  CameraControls(
    onux::Transform& cameraTransform,
    onux::MouseMoveEvent& mouseMoveEvent
  );
  ~CameraControls();

private:
  typedef onux::MouseMoveEvent::Callback OnMouseMove;

  onux::Transform&      m_cameraTransform;
  onux::MouseMoveEvent& m_mouseMoveEvent;
  const OnMouseMove     m_onMouseMove;
  double                m_previousX;
  double                m_previousY;

  const glm::vec3 getRotation(const double x, const double y) const;
};
