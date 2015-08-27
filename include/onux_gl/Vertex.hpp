#pragma once

#include <glm/glm.hpp>

namespace onux_gl {
  using glm::vec2;
  using glm::vec3;

  class Vertex {
    const vec3 position;
    const vec3 normal;
    const vec2 uv;

  public:
    Vertex(const vec3 position, const vec3 normal, const vec2 uv);
    static void attributePointers();
  };
}
