#include "Transform.hpp"

#include <glm/gtc/matrix_transform.hpp>

using glm::vec3;
using glm::mat4;
using glm::radians;

namespace onux {

Transform::Transform()
  : m_scale(vec3(1)) {}

void Transform::translate(const vec3& translation) {
  m_position += translation;
}

void Transform::rotate(const vec3& rotation) {
  m_rotation += rotation;
}

void Transform::scale(const vec3& scale) {
  m_scale *= scale;
}

void Transform::setPosition(const vec3& position) {
  m_position = position;
}

void Transform::setRotation(const vec3& rotation) {
  m_rotation = rotation;
}

void Transform::setScale(const vec3& scale) {
  m_scale = scale;
}

const vec3& Transform::getPosition() const {
  return m_position;
}

const vec3& Transform::getRotation() const {
  return m_rotation;
}

const vec3& Transform::getScale() const {
  return m_scale;
}

const mat4 Transform::getMatrix() const {
  return calculateMatrix(m_position, m_rotation, m_scale);
}

const mat4 Transform::calculateMatrix(
  const vec3& position,
  const vec3& rotation,
  const vec3& scale
) const {
  return glm::scale(glm::rotate(glm::rotate(glm::rotate(glm::translate(mat4()
         , position)
         , radians(rotation.x), vec3(1, 0, 0))
         , radians(rotation.y), vec3(0, 1, 0))
         , radians(rotation.z), vec3(0, 0, 1))
         , scale);
}

} // namespace onux
