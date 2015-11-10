#pragma once

#include <glm/glm.hpp>

#include "graphics/VertexLayout.hpp"

namespace onux {

struct Vertex {
  static const VertexLayout LAYOUT;

  const glm::vec3 POSITION;
  const glm::vec3 NORMAL;
  const glm::vec2 UV;
};

} // namespace onux
