#pragma once

#include <glm/glm.hpp>

using glm::vec3;
using glm::mat4;

class Transform {
  mat4 matrix;

public:
  void translate(const vec3& translation);
  void rotate(const float degrees, const vec3& axis);
  void scale(const vec3& scale);
  const mat4& getMatrix() const;
};
