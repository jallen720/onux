#pragma once

#include <glm/glm.hpp>

#include "graphics/Transform.hpp"
#include "environment/InputEvents.hpp"
#include "environment/Input.hpp"

class CameraControls {
public:
  CameraControls(onux::Transform& cameraTransform, onux::Input& input);
  ~CameraControls();

private:
  typedef onux::MouseMoveEvent::Callback OnMouseMove;

  onux::Transform&  m_cameraTransform;
  onux::Input&      m_input;
  const OnMouseMove m_onMouseMove;
  double            m_previousX;
  double            m_previousY;

  void onMouseMove(const double x, const double y);
  const glm::vec3 getRotation(const double x, const double y) const;
};
