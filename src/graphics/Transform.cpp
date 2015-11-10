#include "graphics/Transform.hpp"

#include <glm/gtc/matrix_transform.hpp>

using glm::vec3;
using glm::mat4;
using glm::radians;

namespace onux {

struct Transform::Impl {
  vec3 position;
  vec3 rotation;
  vec3 scale;

  Impl();
};

Transform::Transform()
  : impl(new Impl()) {}

Transform::~Transform() {}

void Transform::translate(const vec3& translation) {
  impl->position += translation;
}

void Transform::rotate(const vec3& rotation) {
  impl->rotation += rotation;
}

void Transform::scale(const vec3& scale) {
  impl->scale *= scale;
}

void Transform::setPosition(const vec3& position) {
  impl->position = position;
}

void Transform::setRotation(const vec3& rotation) {
  impl->rotation = rotation;
}

void Transform::setScale(const vec3& scale) {
  impl->scale = scale;
}

const vec3& Transform::getPosition() const {
  return impl->position;
}

const vec3& Transform::getRotation() const {
  return impl->rotation;
}

const vec3& Transform::getScale() const {
  return impl->scale;
}

const mat4 Transform::getLocalMatrix() const {
  return glm::scale(glm::rotate(glm::rotate(glm::rotate(glm::translate(mat4()
         , impl->position)
         , radians(impl->rotation.x), vec3(1, 0, 0))
         , radians(impl->rotation.y), vec3(0, 1, 0))
         , radians(impl->rotation.z), vec3(0, 0, 1))
         , impl->scale);
}

const mat4 Transform::getWorldMatrix() const {
  return glm::translate(glm::rotate(glm::rotate(glm::rotate(glm::scale(mat4()
         , impl->scale)
         , -radians(impl->rotation.x), vec3(1, 0, 0))
         , -radians(impl->rotation.y), vec3(0, 1, 0))
         , -radians(impl->rotation.z), vec3(0, 0, 1))
         , -impl->position);
}

// Implementation

Transform::Impl::Impl()
  : scale(vec3(1)) {}

} // namespace onux
