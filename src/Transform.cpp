#include "Transform.hpp"

#include <glm/gtc/matrix_transform.hpp>

void Transform::translate(const vec3& translation) {
  matrix = glm::translate(matrix, translation);
}

const mat4& Transform::getMatrix() const {
  return matrix;
}
