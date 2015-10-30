#pragma once

#include "graphics/Transform.hpp"
#include "environment/listeners/IMouseDeltaListener.hpp"

class CameraControls : public onux::IMouseDeltaListener {
public:
  CameraControls(onux::Transform& cameraTransform);

  // IMouseDeltaListener
  void onMouseDelta(const glm::dvec2& delta) override;

private:
  onux::Transform& m_cameraTransform;
};
