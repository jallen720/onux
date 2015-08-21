#include "Transform.hpp"

#include <glm/gtc/matrix_transform.hpp>

using glm::radians;

void Transform::translate(const vec3& translation) {
  matrix = glm::translate(matrix, translation);
}

void Transform::rotate(const float degrees, const vec3& axis) {
  matrix = glm::rotate(matrix, radians(degrees), axis);
}

void Transform::scale(const vec3& scale) {
  matrix = glm::scale(matrix, scale);
}

const mat4& Transform::getMatrix() const {
  return matrix;
}
