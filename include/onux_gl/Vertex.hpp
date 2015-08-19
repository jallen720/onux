#pragma once

#include <glm/glm.hpp>

namespace onux_gl {
  using glm::vec2;
  using glm::vec3;
  using glm::vec4;

  class Vertex {
    const vec3 position;
    const vec4 color;
    const vec2 texCoord;

  public:
    Vertex(const vec3 position, const vec4 color, const vec2 texCoord);
    static void attributePointers();
  };
}
