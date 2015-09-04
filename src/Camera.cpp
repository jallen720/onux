#include "Camera.hpp"

Camera::Camera(const mat4& projection)
  : projection(projection) {}

Transform& Camera::getTransform() {
  return viewTransform;
}

const mat4& Camera::getProjection() const {
  return projection;
}
