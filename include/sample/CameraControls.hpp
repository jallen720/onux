#pragma once

#include "graphics/Transform.hpp"
#include "environment/Input.hpp"
#include "environment/interfaces/IMouseDeltaListener.hpp"

class CameraControls : public onux::IMouseDeltaListener {
public:
  CameraControls(onux::Transform& cameraTransform, onux::Input& input);
  ~CameraControls();

  // IMouseDeltaListener
  void onMouseDelta(const glm::dvec2& delta) override;

private:
  onux::Transform& m_cameraTransform;
  onux::Input&     m_input;
};
