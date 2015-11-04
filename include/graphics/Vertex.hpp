#pragma once

#include <glm/glm.hpp>

#include "graphics/VertexLayout.hpp"

namespace onux {

class Vertex {
public:
  static const VertexLayout LAYOUT;

public:
  const glm::vec3 POSITION;
  const glm::vec3 NORMAL;
  const glm::vec2 UV;
};

} // namespace onux
