#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

using glm::vec3;
using glm::mat4;

class Transform {
  mat4 matrix;

public:
  void translate(const vec3& translation);
  const mat4& getMatrix() const;
};
