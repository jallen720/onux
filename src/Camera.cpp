#include "Camera.hpp"

Camera::Camera(const mat4& projection)
  : projection(projection) {}

ViewTransform& Camera::getViewTransform() {
  return viewTransform;
}

const mat4& Camera::getProjection() const {
  return projection;
}
