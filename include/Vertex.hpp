#pragma once

#include <glm/glm.hpp>

using glm::vec3;
using glm::vec4;

class Vertex {
  const vec3 position;
  const vec4 color;

public:
  Vertex(const vec3 position, const vec4 color);
  static void attributePointers();
};
