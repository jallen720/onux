#pragma once

#include "graphics/Transform.hpp"
#include "environment/listeners/IMouseMoveListener.hpp"

class CameraControls : public onux::IMouseMoveListener {
public:
  CameraControls(onux::Transform& cameraTransform);

  // IMouseMoveListener
  void onMouseMove(const glm::dvec2& position) override;

private:
  onux::Transform& m_cameraTransform;
  glm::dvec2       m_prevMousePos;

  const glm::vec3 getRotation(const glm::dvec2& currMousePos) const;
};
