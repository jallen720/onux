#include "ViewTransform.hpp"

#include <glm/gtc/matrix_transform.hpp>

using glm::radians;

const mat4 ViewTransform::calculateMatrix(
  const vec3& position,
  const vec3& rotation,
  const vec3& scale
) const {
  return glm::translate(glm::rotate(glm::rotate(glm::rotate(glm::scale(mat4()
         , scale)
         , -radians(rotation.x), vec3(1, 0, 0))
         , -radians(rotation.y), vec3(0, 1, 0))
         , -radians(rotation.z), vec3(0, 0, 1))
         , -position);
}
